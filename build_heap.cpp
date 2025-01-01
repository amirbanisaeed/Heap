#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

using namespace std;

class HeapBuilder
{
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }

    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    void GenerateSwaps() {
        swaps_.clear();
        // The following naive implementation just sorts 
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap, 
        // but in the worst case gives a quadratic number of swaps.
        //
        // TODO: replace by a more efficient implementation

      // Using SiftUP
    /*
        int parent_i = 0;
        for (int j = data_.size() - 1; j > 0; j--)
        {
        //  cout << "Parent: " << parent_i << "  i: " << j << endl;
          int i = j;
          for (;;)
          {
            parent_i = (i - 1) / 2;
            if (data_[parent_i] > data_[i])
            {
              swap(data_[i], data_[parent_i]);
              swaps_.push_back(make_pair(parent_i, i));
            }
           // cout << "Parent: " << parent_i << "  i: " << i << endl;
            i = parent_i;
            if (i == 0)
            {
              break;
            }
          }
        }
        */

        // Using Sift Down

        int n = data_.size();
        for (int i = n / 2; i >= 0; i--)
        {

            SiftDown(i);
        }
    }

    void SiftDown(int i)
    {

        int n = data_.size();
        int max_index;
        int l, r;
        /// cout << "I am in " << i << endl;
        max_index = i;
        l = 2 * i + 1;
        if (l < n && data_[l] < data_[max_index])
        {
            max_index = l;
        }

        r = 2 * i + 2;
        if (r < n && data_[r] < data_[max_index])
        {
            max_index = r;
        }

        if (i != max_index)
        {
            swap(data_[i], data_[max_index]);
            swaps_.push_back(make_pair(max_index, i));
            SiftDown(max_index);
        }

    }

public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
