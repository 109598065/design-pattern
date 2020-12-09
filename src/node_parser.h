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
            try
            {
                token = _scanner->nextToken();
                if(token == "}")
                    _sb->buildFolderEnd();

            }
            catch (std::string e)
            {
                break;
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