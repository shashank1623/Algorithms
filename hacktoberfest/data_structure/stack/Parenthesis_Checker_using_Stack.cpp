class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        int i=0;
        while(i<x.length())
        {
            if(s.empty())
            s.push(x[i]);
            else 
            if(!s.empty() &&(s.top()=='(' && x[i]==')' ||
               s.top()=='{' && x[i]=='}' ||
               s.top()=='[' && x[i]==']' ))
               {
                   s.pop();
               }
               else
              s.push(x[i]);
               i++;
        }
       return s.empty()?true: false;
    }

};

Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)
where 1 ≤ |x| ≤ 32000
