#include<bits/stdc++.h>
using namespace std;
stack< pair <int,int> >st;
int min(int a,int b)
{
    return a > b ? b : a;
}
void priority_push(int new_element)
{
    int new_min = st.empty() ? new_element : min(new_element,st.top().second);
    st.push({new_element,new_min});
}
int return_min(void)
{
    return st.top().second;
}
int priority_pop(void)
{
    int a = st.top().first;
    st.pop();
    return a;
}
int main(void)
{
    int i,x;
    char c;
    cout<<"welcome to the priority stack!!!"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    //cin>>i;
    while(1)
    {
        cin>>c;
        switch(c)
        {
            case '1':
            {
                cin>>x;
                priority_push(x);
                break;
            }
            case '2':
            {
                if(st.empty())
                    cout<<"you moron!!! keep track of popped and pushed elements!!!"<<endl;
                else
                {
                    int lol = priority_pop();
                    cout<<"the popped element is :: "<<lol<<endl;
                }
                break;
            }
            case '3':
            {
                if(st.empty())
                    cout<<"you moron!!! there is no top element!!"<<endl;
                else
                {
                    int yay = return_min();
                    cout<<"the current min is :: "<<yay<<endl;
                }
                break;
            }
            default:
            {
                cout<<"who are you so wise in the ways of science!!"<<endl;
            }
        }
    }
    return 0;
}

