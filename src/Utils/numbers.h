
#pragma once

// TODO: handle negatives
inline int parseInt(std::string &s) {
    int result = 0;
    for (char const &c: s) {
        result *= 10;
        result += c - '0';
    }
    return result;
}


// TODO: handle negatives
inline int parseIntUntil(std::string &s, int until) {
    int result = 0;

    for (int i =0; i < until; i++){
        result *= 10;
        result += s[i] - '0';
    }
    return result;
}

// TODO: handle negatives
inline int parseIntUntil(std::string_view &s, int until) {
    int result = 0;

    for (int i =0; i < until; i++){
        result *= 10;
        result += s[i] - '0';
    }
    return result;
}


// TODO: handle negatives
inline int parseSignedInt(std::string &s) {
    int result = 0;
    for (int i =1; i < s.size(); i++){
        // result = (result << 1) + (result << 3);
        result = result * 10;
        result += s[i] - '0';
    }

    if (s[0] == '-'){
        return -result;
    }
    return result;


    // return (int[]) {result, -result}[(s[0] == '-')];
}

