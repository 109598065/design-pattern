#ifndef NODE_SCANNER_H
#define NODE_SCANNER_H

class NodeScanner
{
public:
    NodeScanner(std::string input) : _input(input) {}
    std::string nextToken()
    {
        if (_input.empty())
            throw std::string("next token doesn't exist.");

        bool isFind = false;
        int state = 0;
        std::string temp;

        while (!isFind) {
            char c = _input.front();
            switch (state) {
                case 0 :
                    if (isalpha(c))state = 1;
                    else if (c == '-') state = 2;
                    else if (isdigit(c))state = 2;
                    else if (c == '(')state = 3;
                    else if (c == ')')state = 3;
                    else if (c == ',')state = 3;
                    else if (c == '{')state = 3;
                    else if (c == '}')state = 3;
                    else state = 4;
                    break;
                case 1:
                    if (!isalpha(c)) {
                        isFind = true;
                    } else {
                        temp.push_back(c);
                        _input = _input.substr(1);
                    }
                    break;
                case 2:
                    if (c == '-' || c == '.' || isdigit(c)) {
                        temp.push_back(c);
                        _input = _input.substr(1);
                    } else {
                        isFind = true;
                    }
                    break;
                case 3:
                    temp.push_back(c);
                    _input = _input.substr(1);
                    isFind = true;
                    break;
                case 4:
                    if (_input.empty())
                        throw std::string("next token doesn't exist.");
                    _input = _input.substr(1);
                    state = 0;
                    break;
            }
        }
        return temp;
    }

private:
    std::string _input;
};
#endif