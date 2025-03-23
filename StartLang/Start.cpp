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
        //cout << "Got: " << word << endl;
        return keywords.count(word) ? keywords[word] : IDENTIFIER;
    }

    Token getSymbolToken(){
        //cout << "Got: " << source[pos] << endl;
        switch(source[pos]){
            case '\'':
                {string value = "";
                for (int i = 1; i < source.size() - pos; i++){
                    if (source[pos + i] == '\''){
                        i++;
                        pos+=i;
                        //cout<<value<<endl;
                        return Token{STRING, value};
                    }
                    value += source[pos+i];
                }
                cout << "WARNING: quotation mark not closed" << endl;
                }break;
            case '\"':
                {string value = "";
                for (int i = 1; i < source.size() - pos; i++){
                    if (source[pos + i] == '\"'){
                        i++;
                        pos+=i;
                        //cout<<value<<endl;
                        return Token{STRING, value};
                    }
                    value += source[pos+i];
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
            case '(':
                pos++;
                return {LPAREN, "("};
            case ')':
                pos++;
                return {RPAREN, ")"};
            case '{':
                pos++;
                return {LBRACE, "{"};
            case '}':
                pos++;
                return {RBRACE, "}"};
            default:
                cout << "Pos: " << pos << endl;
                cout << "WARNING: unknown command " << source[pos] << endl;
                return Token{UNKNOWN, source[pos]+""};
        }
        cout << "REACHED HERE 100" << endl;
        return Token{UNKNOWN, ""};
    }
};

class Interpreter;

struct Function {
    vector<Token> body;
    unordered_map<string, string> locals;
    vector<string> args;
    vector<string> returnValue;
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

    //Execute all code according to the tokens received
    void execute(const vector<Token>& tokens){
        for (int i = 0; i < tokens.size(); i++){
            //cout << tokens[i].type << endl;
            if (tokens[i].type == PRINT){
                //cout << "calling method" << endl;
                methods(tokens, i);
            }
        }
        cout << "End of program" << endl;
    }

    //Evaluate expressions such as conditional, loop and 
    /*string evaluateExpression(const vector<Token>& tokens, size_t& i, const unordered_map<string, string>& locals, const unordered_map<string, string>& fields, Class& cls){
    }

    //Execute the method of a given class
    string executeMethod(Class& cls, Function& method){
    }*/
    
    //Default methods available for all the program
    string methods(const vector<Token>& tokens, int currentIndex){
        switch(tokens[currentIndex].type){
            case PRINT:
                {string value;
                TokenType type = tokens[currentIndex].type;
                //Ignores "print" and LPAREN
                currentIndex += 2;
                int LParenAmount = 1;
                while (currentIndex < tokens.size()){
                    type = tokens[currentIndex].type;
                    if (type == STRING){
                        value += tokens[currentIndex].value;
                        //continue;
                    }
                    else if (type == LPAREN){
                        LParenAmount++;
                        //manage concats, etc
                        
                    }
                    else if (type == RPAREN){
                        LParenAmount--;
                        if (LParenAmount == 0) {
                            break;
                        }
                    }
                    currentIndex++;
                }
                if (LParenAmount != 0) {
                    cout << "WARNING: Print statement have unequal quantities of left and right parenthesis" << endl;
                }
                //Prints
                cout << value << endl;
                }
                break;
            default:
                cout << "Couldnt identify method " << tokens[currentIndex].type << endl;
        }
        return "";
    }
};




int main(int argc, char* argv[]) {
    string source = "print(\"Hello World!\")";
    Lexer lexer(source);
    vector<Token> tokens = lexer.tokenize();
    
    Interpreter interpreter;
    interpreter.execute(tokens);
    
    return 0;
}
