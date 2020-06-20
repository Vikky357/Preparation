/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/


class Solution {
    struct Trie
    {
        int data;
        int wc;
        Trie* child[26];
    }*root;
    Trie* getnode()
    {
        Trie* newnode=new Trie();
        newnode->wc=0;
        for(int i=0;i<26;i++)
            newnode->child[i]=NULL;
        return newnode;
            
    }
    void insert(string s)
    {
        Trie* curr=root;
        int index;
        for(int i=0;i<s.size();i++)
        {
            index=s[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index]=getnode();
            curr=curr->child[index];
            curr->data=s[i];
            curr->wc+=1;
        }
    }
    string check(int len,string s)
    {
        Trie* curr=root;
        int index;
        string output;
        for(int i=0;i<s.size();i++)
        {
            index=s[i]-'a';
            if(curr->child[index]==NULL || curr->child[index]->wc!=len)
                break;
            output.push_back(s[i]);
            curr=curr->child[index];
        }
        return output;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        root=getnode();
        int len=strs.size();
        if(len==0)
            return "";
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            insert(s);
            
        }
        return (check(len,strs[0]));
        
    }
};
