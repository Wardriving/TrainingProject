#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Header.h"
#include <stack>
#include <bitset>

using queue_t = std::priority_queue < Node::pointer, std::vector<Node::pointer>, LowestPriority >;

std::ifstream::pos_type get_size(const std::string& fn)
{
    std::ifstream ifs(fn, std::ifstream::ate);
    return ifs.tellg();
}

void read_file(const std::string& filename, std::vector<int>& frequency)
{
    auto filesize = get_size(filename);
    if (filesize < 0)
    {
        std::cerr << "Error << endl";
    }
    std::ifstream ifs(filename, std::ifstream::binary);
    if (!ifs)
    {
        std::cerr << "Error << endl";
    }

    int i = 0;

    std::cout << "Reading file" << filename << ":" << std::endl;

    while (true)
    {
        char ch;
        ifs.read(&ch, 1);
        if (ifs.eof())
        {
            break;
        }

        frequency[static_cast<unsigned char>(ch)]++;

        if (i % 20 == 0)
        {
            auto value = i * 100.0 / filesize;
            std::cout << "\r" << value << "%" << std::flush;
        }
        ++i;
    }
    std::cout << std::endl;
}

void make_code(Node::pointer& node, std::string str, std::vector<std::string>& codes)
{
    if (node->left != nullptr)
    {
        make_code(node->left, str + "0", codes);
    }
    if (node->right != nullptr)
    {
        make_code(node->right, str + "1", codes);
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        node->code(str);
        codes[node->get_byte()] = str;
        std::cout << "leaf:" << *node << "code:" << node->code() << "\n";
    }
}

void iterative_make_code(Node::pointer& root, std::vector<std::string>& codes)
{
    std::stack<Node::pointer> tree_stack;
    tree_stack.push(root);

    Node::pointer node = tree_stack.top();
    while (!(root->left == nullptr && root->right == nullptr))
    {
        if (node->right != nullptr)
        {
            node->right->code(node->code() + "1");
            tree_stack.push(node->right);
        }
        if (node->left != nullptr)
        {
            node->left->code(node->code() + "0");
            tree_stack.push(node->left);
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            node->code(node->parent->code());

            if (node == node->parent->left)
            {
                node->code(node->code() + "0");
                node->parent->left = nullptr;
            }
            else if (node == node->parent->right)
            {
                node->code(node->code() + "1");
                node->parent->right = nullptr;
            }

            if (node->is_leaf());
            {
                codes[node->get_byte()] = node->code();
                std::cout << "leaf:" << *node << "code:" << node->code() << "\n";
            }
            tree_stack.pop();
        }
        node = tree_stack.top();
    
    }
}

void fill_queue(std::vector<int>& frequency, queue_t& queue)
{
    for_each(frequency.begin(), frequency.end(), [byte = uchar{0}, &queue](const auto& value) mutable
        {
            if (value != 0)
            {
                Node::pointer node = std::make_shared<Node>(byte, value);
                queue.push(node);
            }
            ++byte;
        });
}

void build_tree(queue_t& queue)
{
    while (queue.size() > 1)
    {
        Node::pointer x = queue.top();
        queue.pop();
        Node::pointer y = queue.top();
        queue.pop();

        std::string name = x->get_name() + y->get_name();

        Node::pointer z = std::make_shared<Node>(name, x->get_frequency() + y->get_frequency());

        z->left = x;
        z->right = y;

        x->parent = z;
        y->parent = z;
        queue.push(z);
    }
}
    std::string message2code(const std::string & filename, std::vector<std::string>&codes)
    {
        std::string msg{ "" };
        std::ifstream ifs(filename, std::ifstream::binary);
        if (!ifs)
        {
            std::cerr << "Error << endl";
            return msg;
        }
        while (true)
        {
            char ch;
            ifs.read(&ch, 1);

            if (ifs.eof())
            {
                break;
            }
            msg += codes[static_cast<uchar>(ch)] + "|";
        }
        return msg;
    }

    void write_file(const std::string& filename, std::vector<int>& frequency, const queue_t& queue, const std::string& message)
    {
        std::string new_filename = filename + ".hff";
        std::ofstream ofs(new_filename, std::ofstream::binary);
        if (!ofs)
        {
            std::cerr << "Error << endl";
            return;
        }


        uchar count = std::count_if(frequency.begin(), frequency.end(), [](const int& value) {return(value != 0); });
        std::cout << "Count:" << (int)count << std::endl;

        ofs.write(reinterpret_cast<char*>(&count), sizeof count);
        for_each(frequency.begin(), frequency.end(), [index = uchar(0), &ofs](int& value) mutable
        {
            if (value != 0)
            {
                std::cout << "[" << index << "] = " << value << "\n";
                ofs.write(reinterpret_cast<char*>(&index), sizeof index);
                ofs.write(reinterpret_cast<char*>(&value), sizeof value);
            }
            ++index;
        });
        int byte_count = message.size() / CHAR_BIT;
        uchar modulo = message.size() % CHAR_BIT;
        std::cout << "byte count:" << byte_count << "of size" << message.size() << "\n";
        std::cout << "modulo:" << (int)modulo << "of size" << message.size() << "\n";

        ofs.write(reinterpret_cast<char*>(&byte_count), sizeof byte_count);
        ofs.write(reinterpret_cast<char*>(&modulo), sizeof modulo);

        int i = 0;
        for (; i < byte_count; ++i)
        {
            std::bitset<CHAR_BIT> b(message.substr(i * CHAR_BIT, CHAR_BIT));
            uchar value = static_cast<uchar>(b.to_ulong());
            ofs.write(reinterpret_cast<char*>(&value), sizeof value);
        }
        if (modulo > 0)
        {
            std::bitset<CHAR_BIT> b(message.substr(i * CHAR_BIT, modulo));
            uchar value = static_cast<uchar>(b.to_ulong());
            ofs.write(reinterpret_cast<char*>(&value), sizeof value);
        }
    }

int main()
{
    std::string filename = "text.txt";
    std::vector<int> frequency(0x100, 0);
    read_file(filename, frequency);

    queue_t queue;

    fill_queue(frequency, queue);
    build_tree(queue);

    std::vector<std::string> codes(0x100, "");
    Node::pointer root = queue.top();
    make_code(root, "", codes);

    std::string message = message2code(filename, codes);
    std::cout << message << std::endl;

    write_file(filename, frequency, queue, message );
}/* разобраться с всем этим кодом обязательно.
is_leaf в хэдере дописать. Вот инфа 100тка потом не разберу
что до чего тут*/