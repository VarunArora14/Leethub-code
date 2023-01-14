class Solution {
public:
    int parent[100000];

void makeSet()
{
  for (int i = 0; i < 26; i++)
  {
    parent[i] = i; // make self parents
  }
}

int findParent(int node)
{
  // check if self parent
  if (node == parent[node])
  {
    return node;
  }
  // otherwise find parent[node] till above condition holds true
  return parent[node] = findParent(parent[node]);

}

// If we call recursive func we are not compressing the path. By doing parent[node] = findParent(parent[node]) we recursively call finding self parent and
// then assign the current node parent as that element compressing the path

void Union(int f, int s)
{
  // Find parent of both
  f = findParent(f);
  s = findParent(s);
 
    if(f==s) return;
    if(f<s)
    {
        parent[s]=f;
    }
    else parent[f]=s;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int n=s1.length();
        makeSet();
        for(int i=0;i<n;i++)
        {
            int v1 = s1[i]-97;
            int v2 = s2[i]-97;
            Union(v1, v2);
        }
        
        for(char& ch: baseStr)
        {
            int val = ch-'a';
            char newch = findParent(val)+'a'; // don't do parent[val] as we have to find the parent first
            ch=newch;
        }
        
        return baseStr;
    }
};
// union find on both str1 and str2 of same indices and then check baseStr