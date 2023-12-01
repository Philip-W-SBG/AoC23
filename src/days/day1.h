#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "../Utils/numbers.h"


inline int isInt(char c){ return (c - '0' & -(c - '0' >= 1 && c - '0' <=9)); }

char* numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

inline bool compareFromIndex(std::string &s, char* ss, int start){
    for (int j = 0; j < strlen(ss); j++){
        if (s[j + start] != ss[j]) return false;
    }
    return true;
}

inline int parseTextNumber(std::string &line, int start){
    char startChar = line[start];
    if (
        startChar != 'o' &
        startChar != 't' & 
        startChar != 'f' & 
        startChar != 's' & 
        startChar != 'e' &
        startChar != 'n'   
        ) return -1;


    for (int i =1; i < 10; i++){
        if (compareFromIndex(line, numbers[i], start)){
            return i;
        }
    }
    return -1;
}

std::pair<int, int> parseNum(std::string &line){
    int part1First = -1;
    int part1Last = -1;

    int part2First = -1;
    int part2Last = -1;
    int j = 0;

    while (part2First == -1 || part1First == -1){
        int res = isInt(line[j]);

        if (res){
            part1First = res;
            if (part2First == -1) part2First = res;
            // part2First = (res & (-(part2First == -1))) | (res & (-(part2First != -1)));
            break;
        }

        if (part2First == -1){
            part2First = parseTextNumber(line, j);        
        }

        j++;
    }
    j = line.size() -1;

    while (part1Last == -1 || part2Last == -1){
        int res = isInt(line[j]);

        if (res){
            if (part1Last == -1) part1Last = res;
            if (part2Last == -1) part2Last = res;
            break;
        }

        if (part2Last == -1){
                part2Last = parseTextNumber(line, j);
        }

        j--;
    }

    int p1 = ((part1First << 3) + (part1First << 1)) + part1Last;
    int p2 = ((part2First << 3) + (part2First << 1)) + part2Last;
    return std::pair<int, int>(p1, p2);
}

void day1(std::vector<std::string> &lines, result &res) {
    int total1 = 0;
    int total2 = 0;
    for (int i=0; i < lines.size(); i++){
        std::string line = lines[i];
        std::pair<int, int> r = parseNum(line);
        
        total1 += r.first;
        total2 += r.second;

    }
    res.intResult1 += total1;
    res.intResult2 += total2;
}



// Part1: 54573
// part 2: 54591
