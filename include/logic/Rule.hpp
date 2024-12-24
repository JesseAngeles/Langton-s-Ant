#ifndef RULE_HPP
#define RULE_HPP

#include <vector>
#include <string>

enum class Rule
{
    LEFT,
    RIGHT
};

inline std::vector<Rule> stringToRules(std::string &rule)
{
    std::vector<Rule> rules;
    for (const char c : rule)
        if (c == 'L')
            rules.push_back(Rule::LEFT);
        else if (c == 'R')
            rules.push_back(Rule::RIGHT);
    
    return rules;
}

#endif // RULE_HPP