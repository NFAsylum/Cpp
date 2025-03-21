#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;

// Token definitions
enum TokenType{
    //Basic
    CLASS, IDENTIFIER, STRING, NUMBER, PUBLIC, FUNCTION,
    //Math operators
    PLUS, MINUS, DIVIDE, MULTIPLY, PLUS_EQUAL, MINUS_EQUAL, DIVIDE_EQUAL, MULTIPLY_EQUAL,
    //Assignment
    LOCAL, EQUAL, DOUBLE_EQUAL, TRIPLE_EQUAL, INCREMENT, DECREMENT, SQUARED, SQUARED_ROOT,
    //Other
    DOT, DOUBLE_DOT, LQUOT, RQUOT, PRINT, LBRACE, RBRACE, LPAREN, RPAREN, RETURN, END, UNKNOWN,
    //Conditional
    IF, SWITCH, EQUATES, NOT_EQUAL, GREATER_THAN, GREATER_EQUAL_THAN, LESS_THAN, LESS_EQUAL_THAN,
    //Loop
    FOR, WHILE, COUNT,
    //Logic
    OR, AND, XOR, NOT, TRUE, FALSE
};

struct Token{
    TokenType type;
    string value;
    string identifier;
};

class Lexer {
public:
    Lexer(const string& source) : source(source), pos(0){}

    vector<Token> tokenize(){
        vector<Token> tokens;
        while (pos < source.size()){
            if (isspace(source[pos])){
                pos++;
                continue;
            }
            if (isalpha(source[pos])){
                string word;
                while (pos < source.size() && isalnum(source[pos])){
                    word += source[pos++];
                }
                tokens.push_back({ getKeywordType(word), word});
                continue;
            }
            if (isdigit(source[pos])) {
                string num;
                while (pos < source.size() && isdigit(source[pos])){
                    num += source[pos++];
                }
                tokens.push_back({ NUMBER, num});
                continue;
            }
            tokens.push_back(getSymbolToken());
        }
        tokens.push_back({ END, ""});
        return tokens;
    }

private:
    string source;
    size_t pos;

    TokenType getKeywordType(const string& word) {
        static unordered_map<string, TokenType> keywords = {
            {"class", CLASS}, {"local", LOCAL}, {"public", PUBLIC}, {"function", FUNCTION},
            {"print", PRINT}, {"return", RETURN}, {"if", IF}, {"switch", SWITCH}, {"for", FOR},
            {"while", WHILE}, {"count", COUNT}, {"or", OR}, {"and", AND}, 
            {"xor", XOR}, {"not", NOT}, {"true", TRUE}, {"false", FALSE}
        };
        return keywords.count(word) ? keywords[word] : IDENTIFIER;
    }

    Token getSymbolToken(){
        switch(source[pos]){
            case '\'': {
                string value = "\'";
                for (int i = 1; i < source.size() - pos; i++){
                    value += source[pos+i];
                    if (value[i] == '\''){
                        pos+=i;
                        return Token{STRING, value};
                    }
                }
                cout << "WARNING: quotation mark not closed" << endl;
                }break;
            case '\"':
                {string value = "\"";
                for (int i = 1; i < source.size() - pos; i++){
                    value += source[pos+i];
                    if (value[i] == '\"'){
                        pos+=i;
                        return Token{STRING, value};
                    }
                }
                cout << "WARNING: double quotation mark not closed" << endl;
                }break;
            case '=':
                if (pos+1 < source.size()){
                    if (pos+2 < source.size() && source[pos+1] == '='){
                        if (source[pos+2] == '='){
                            pos+=3;
                            return Token{TRIPLE_EQUAL, "==="};
                        }
                        pos+=2;
                        return Token{DOUBLE_EQUAL, "=="};
                    }
                    pos++;
                    return Token{EQUAL, "="};
                }
                cout << "WARNING: assign operator incomplete" << endl;
                break;
            case '-':
                if (pos+1 < source.size()){
                    if (source[pos+1] == '='){
                        pos+=2;
                        return Token{MINUS_EQUAL, "-="};
                    }
                    if (source[pos+1] == '-'){
                        pos+=2;
                        return Token{DECREMENT, "--"};
                    }
                    pos++;
                    return Token{MINUS, "-"};
                }
                cout << "WARNING: minus operator incomplete" << endl;
                break;
            case '+':
                if (pos+1 < source.size()){
                    if (source[pos+1] == '='){
                        pos+=2;
                        return Token{PLUS_EQUAL, "+="};
                    }
                    if (source[pos+1] == '+'){
                        pos+=2;
                        return Token{INCREMENT, "++"};
                    }
                    pos++;
                    return Token{PLUS, "+"};
                }
                cout << "WARNING: plus operator incomplete" << endl;
            case '*':
                if (pos+1 < source.size()){
                    if (source[pos+1] == '='){
                        pos+=2;
                        return Token{MULTIPLY_EQUAL, "*="};
                    }
                    if (source[pos+1] == '*'){
                        pos+=2;
                        return Token{SQUARED, "**"};
                    }
                    pos++;
                    return Token{PLUS, "*"};
                }
                cout << "WARNING: multiply operator incomplete" << endl;
                break;
            case '/':
                if (pos+1 < source.size()){
                    if (source[pos+1] == '='){
                        pos+=2;
                        return Token{DIVIDE_EQUAL, "/="};
                    }
                    if (source[pos+1] == '/'){
                        pos+=2;
                        return Token{SQUARED_ROOT, "//"};
                    }
                    pos++;
                    return Token{DIVIDE, "/"};
                }
                cout << "WARNING: divide operator incomplete" << endl;
                break;
            
        }
    }
};

class Interpreter;

struct Function {
    vector<Token> body;
    unordered_map<string, string> locals;
    vector<string, string> args;
    vector<string, string> returnValue;
};

struct Class {
    unordered_map<string, string> fields;
    unordered_map<string, Function> methods;
};

class Interpreter{
private:
    unordered_map<string, string> globals;
    unordered_map<string, Class> classes;
    unordered_map<string, Function> functions;

public:
    Interpreter() {}

    void execute(const vector<Token>& tokens){
    }

    string evaluateExpression(const vector<Token>& tokens, size_t& i, const unordered_map<string, string>& locals, const unordered_map<string, string>& fields, Class& cls){
    }

    string executeMethod(Class& cls, Function& method){
    }
};




int main(int argc, char* argv[]) {
    return 0;
}
