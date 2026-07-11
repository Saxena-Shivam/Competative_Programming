
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2] = {nullptr};
    int cnt = 0;

    bool containsKey(int bit)
    {
        return links[bit] != nullptr;
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
                node->put(bit, new Node());

            node = node->get(bit);
            node->cnt++;
        }
    }

    void remove(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            node = node->get(bit);
            node->cnt--;
        }
    }

    int getMaxXor(int num)
    {
        Node *node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (node->containsKey(1 - bit) && node->get(1 - bit)->cnt > 0)
            {
                ans |= (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int maxXor(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> px(n + 1, 0);
        for (int i = 0; i < n; i++)
            px[i + 1] = px[i] ^ nums[i];
        deque<int> minD, maxD;
        Trie trie;
        trie.insert(0);
        int l = 0, ans = 0;
        for (int r = 0; r < n; r++)
        {
            while (!minD.empty() && nums[minD.back()] >= nums[r])
                minD.pop_back();

            while (!maxD.empty() && nums[maxD.back()] <= nums[r])
                maxD.pop_back();
            minD.push_back(r);
            maxD.push_back(r);
            while (nums[maxD.front()] - nums[minD.front()] > k)
            {
                trie.remove(px[l]);

                if (minD.front() == l)
                    minD.pop_front();
                if (maxD.front() == l)
                    maxD.pop_front();

                l++;
            }
            ans = max(ans, trie.getMaxXor(px[r + 1]));
            trie.insert(px[r + 1]);
        }

        return ans;
    }
};
