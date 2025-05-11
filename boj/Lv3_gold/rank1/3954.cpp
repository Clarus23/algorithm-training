#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int sm, sc, si;
        cin >> sm >> sc >> si;

        vector<unsigned int> mem(sm, 0);
        int mptr = 0;

        string code, input;
        cin >> code >> input;
        int iptr = 0, cptr = 0;

        vector<int> loopOp(code.size(), -1);
        vector<int> stack(code.size(), 0);
        int top = -1;
        for(int i=0; i<code.size(); i++) {
            if(code[i] == '[') {
                stack[++top] = i;
            } else if(code[i] == ']') {
                loopOp[i] = stack[top];
                loopOp[stack[top--]] = i;
            } else continue;
        }

        int loopStart = code.size();
        for(int exe=0; exe<100000000; exe++, cptr++) {
            if(cptr >= code.size()) break;

            if(code[cptr] == '-') mem[mptr] = (mem[mptr] == 0) ? 255 : --mem[mptr];
            else if(code[cptr] == '+') mem[mptr] = (mem[mptr] == 255) ? 0 : ++mem[mptr];
            else if(code[cptr] == '<') mptr = (mptr == 0) ? sm - 1 : --mptr;
            else if(code[cptr] == '>') mptr = (mptr == sm - 1) ? 0 : ++mptr;
            else if(code[cptr] == '[') { if(mem[mptr] == 0) cptr = loopOp[cptr]; }
            else if(code[cptr] == ']') { if(mem[mptr] != 0) cptr = loopOp[cptr]; }
            else if(code[cptr] == '.') ;
            else if(code[cptr] == ',') mem[mptr] = (iptr < input.size()) ? (int)input[iptr++] : 255;

            if(exe > 50000000) loopStart = (cptr < loopStart) ? cptr : loopStart;
        }

        if(cptr >= code.size()) cout << "Terminates\n";
        else cout << "Loops " << loopStart << ' ' << loopOp[loopStart] << '\n';
    }

    return 0;
}