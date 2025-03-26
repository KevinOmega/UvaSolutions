#include <cstdio>
#include <stack>


using namespace std;


void cleanStack(stack<int> (&spaces)[30],int (&blocks)[30],int block ){
    stack<int> &pile = spaces[blocks[block]];
    int currentBlock = pile.top();
    
    while (currentBlock != block)
    {
        currentBlock = pile.top();
        pile.pop();
        spaces[currentBlock].push(currentBlock);
        blocks[currentBlock] = currentBlock;
    }
}

void pileStack(stack<int> (&spaces)[30], int (&blocks)[30], int a, int b ){
    stack<int>& pile1 = spaces[blocks[a]];
    stack<int>& pile2 = spaces[blocks[b]];
    int currentBlock;
    stack<int> handStack;
    if(!pile1.empty()){
        do
        {
        currentBlock = pile1.top();
        pile1.pop();
        handStack.push(currentBlock);
        blocks[currentBlock] = blocks[b];
        } while (currentBlock != a);
        while (!handStack.empty())
        {
            pile2.push(handStack.top());
            handStack.pop();
        } 
    }
    

}

int main(){
    int n;    
    char inst1[10],inst2[10];
    int a,b;
    stack<int> spaces[30];
    int blocks [30];
    bool first = true;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
       {
        spaces[i].push(i);
        blocks[i] = i;
        }
    while (scanf("%s", &inst1) && inst1[0] != 'q')
    {
        
       scanf("%d %s %d", &a,&inst2,&b);
       if(blocks[a] != blocks[b]){
            if(inst1[0] == 'm'){
                if (inst2[1] == 'v')
                {
                    cleanStack(spaces,blocks,a);
                    spaces[blocks[b]].push(a);
                    spaces[blocks[a]].pop();
                    blocks[a] = blocks[b];
                }else{
                    cleanStack(spaces,blocks,a);
                    cleanStack(spaces,blocks,b);
                    spaces[blocks[b]].push(a);
                    spaces[blocks[a]].pop();
                    blocks[a] = blocks[b];
                }
                
            }else{
                if (inst2[1] == 'v')
                {
                    pileStack(spaces, blocks, a,b);
                }else{
                    cleanStack(spaces,blocks,b);
                    pileStack(spaces,blocks,a,b);
                }
            } 
       }
          
    }
    for (int i = 0; i < n; i++)
    {
        
        printf("%d:", i);

        stack<int> &currentStack = spaces[i];
        stack<int> handStack;
        while (!currentStack.empty())
        {
            handStack.push(currentStack.top());
            currentStack.pop();   
        }
        while (!handStack.empty())
        {
            printf(" %d", handStack.top());
            handStack.pop();
        }
        printf("\n");
    }
    
    return 0;
}
