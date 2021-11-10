#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int error_at = 0;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position+1));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            Bracket top = opening_brackets_stack.top();
            if(opening_brackets_stack.empty() ||!top.Matchc(next)){
                error_at = position +1;
                break;
            }

			opening_brackets_stack.pop();
        }
    }

    // Printing answer, write your code here

    if(error_at==0 && opening_brackets_stack.empty())
		std::cout << "Success";
	else {
		if(error_at == 0) {
			while(opening_brackets_stack.size()>1)
				opening_brackets_stack.pop();
			error_at = opening_brackets_stack.top().position;
		}
		std::cout << error_at;
	}

    return 0;
}
