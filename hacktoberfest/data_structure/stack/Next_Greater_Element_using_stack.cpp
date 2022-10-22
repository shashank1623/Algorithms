class Solution{
  
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> s, int n)
        {
            stack<long long> s1;
            vector<long long> v;
            // long long i=n-1;
           for(int i=n-1;i>=0;i--)
            {
                if(s1.empty())
                v.push_back(-1);
                else if(s1.size()>0 && s1.top()>s[i])
                    v.push_back(s1.top());
                else 
                {
                    while(!s1.empty() && s1.top()<=s[i])
                    {
                        s1.pop();
                    }
                    if(!s1.empty())
                       v.push_back(s1.top());
                        
                    else
                        v.push_back(-1);
                        
                   
                }
                 s1.push(s[i]);
                // i--;
            }
            reverse(v.begin(),v.end());
            return v;
               
        }
};
