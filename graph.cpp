#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>

Graph::Graph(std::string filePath){readtxt(filePath);}

void Graph::readtxt(std::string filePath)
{
    std::string line;
    char lineSeparator = '\n';
    char innerSeparator = ' ';
    char coordinateSeparator = '(';

    char nodeName;

    int i;
    size_t pos = 0;
    std::ifstream in(filePath);
    std::cout<<std::endl;
    if (in.is_open())
    {
        while (std::getline(in, line, lineSeparator))
        {
            i = 0;
            std::stringstream ss(line);
            std::string word;
            while (ss >> word) { // Extract word from the stream.

                switch(i)
                {
                case 0:
                    pos = word.find('(');
                    std::string node = word.substr(0, pos);
                    std::cout <<node;

                    break;

                default:

                    break;
                }
                i++;
            }

        }
        std::cout << std::endl;
    }

    in.close();

    return;
}

int Graph::get_edge_weight(const Node& keyNode, const Node& childNode)
{
    return 0;
}

/*
            std::string s;
            //std::remove_if(line.begin(), line.end(), isspace);
            size_t pos = 0;
            while ((pos = line.find(innerSeparator)) != std::string::npos) {
                s = line.substr(0, pos);
                std::cout << s;
                line.erase(0, pos+1);
            }
            if(line.length() != 0)
            {
                std::cout << line;
            }
               std::cout<< std::endl;

            }*/
