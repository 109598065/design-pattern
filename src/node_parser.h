#ifndef NODE_PARSER_H
#define NODE_PARSER_H

#include <vector>
#include "./node_builder.h"
#include "./node_scanner.h"

class NodeParser
{
public:
    NodeParser(std::string input)
    {
        _scanner = new NodeScanner(input);
        _sb = new NodeBuilder();
    }

    void parser()
    {
        while (1)
        {
            std::string token, temp;
            int state = 0;
            try
            {
                token = _scanner->nextToken();
                if (token == "}")
                {
                    _sb->buildFolderEnd();
                    state = 0;
                }

                if ("(" == (temp = _scanner->nextToken()))
                {
                    double size = stod(_scanner->nextToken());
                    _scanner->nextToken();
                    _sb->buildApp(token, size);
                }
                else if ("{" == temp)
                {
                    _sb->buildFolderBegin(token);
                    state = 1;
                }

                if (state == 1)
                {
                    if ("}" == _scanner->nextToken())
                        _sb->buildFolderEnd();
                }
            }
            catch (std::string e)
            {
                break;
            }
        }
    }
    std::deque<Node *> getResult()
    {
        return _sb->getResult();
    }

private:
    NodeScanner *_scanner;
    NodeBuilder *_sb;
};

#endif