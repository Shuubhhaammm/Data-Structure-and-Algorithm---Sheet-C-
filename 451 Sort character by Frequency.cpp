class Solution
{
public:
  // Function to sort characters based on their frequencies
  string frequencySort(string s)
  {
    int n = s.length();

    // Map to store the frequency of each character
    map<char, int> mp;
    for (int i = 0; i < n; ++i)
    {
      mp[s[i]]++;
    }

    // Vector to store pairs of frequencies and characters
    vector<pair<int, char>> v;
    for (auto &ele : mp)
    {
      v.push_back({ele.second, ele.first});
    }

    // Sorting the vector based on frequencies in ascending order
    sort(v.begin(), v.end());

    // Constructing the result string by appending characters based on their frequencies in reverse order
    string ans;
    for (int i = 0; i < v.size(); ++i)
    {
      for (int j = 0; j < v[i].first; j++)
      {
        ans += v[i].second;
      }
    }

    // Reversing the string to get characters in descending order of frequencies
    reverse(ans.begin(), ans.end());
    return ans;
  }
};