#define DATA_CHUNK_SIZE 8
#include <iostream>
#include <string>
#include "../vector/kt_vector.cpp"
#include <utility>

using namespace std;

namespace KT {

template <typename T>
class dequeue {
    
    private:
        typedef pair<pair<int,int>,T*> DataChunk;
        kt_vector<DataChunk> _chunk_connector;
        int _rear_chunk, _head_chunk, _rear_node, _head_node, _size;

        bool headOverflow() {
            return _head_node >= DATA_CHUNK_SIZE - 1;
        }
        
        bool rearOverflow() {
            return _rear_node <= 0;
        }
        
        void allocateHead() {
            T* tmp = new T[DATA_CHUNK_SIZE];
            int new_chunk_idx = _chunk_connector.size();
            _chunk_connector[_head_chunk].first.second = new_chunk_idx;
            _chunk_connector.push_back( 
               DataChunk(pair<int,int>(_head_chunk,-1), tmp) 
            );
            _head_chunk = new_chunk_idx;
            _head_node = 0;
        }
        
        void allocateRear() {
            T* tmp = new T[DATA_CHUNK_SIZE];
            int new_chunk_idx = _chunk_connector.size();
            _chunk_connector[_rear_chunk].first.first = new_chunk_idx;
            _chunk_connector.push_back( 
                DataChunk(pair<int,int>(-1, _rear_chunk), tmp) 
            );
            _rear_chunk = new_chunk_idx;
            _rear_node = DATA_CHUNK_SIZE - 1;
        }
    
    public:
        dequeue() {
            T* tmp = new T[DATA_CHUNK_SIZE];
            _chunk_connector.push_back( 
                DataChunk(pair<int,int>(-1,-1), tmp) 
            );
            _rear_chunk = _head_chunk = 0;
            _head_node = DATA_CHUNK_SIZE / 2;
            _rear_node = _head_node - 1;
        }
        
        void push_back(T data) {
            if (headOverflow()) allocateHead();
            (_chunk_connector[_head_chunk].second)[_head_node++] = data;
        }
        
        void push_front(T data) {
            if (rearOverflow()) allocateRear();
            (_chunk_connector[_rear_chunk].second)[_rear_node--] = data;
        }

        T pop_front() {
            T data = *((_chunk_connector[_head_chunk].second)[_head_node--]);
            if (_head_node == -1) {
                int to_delete = _head_chunk;
                _head_chunk = _chunk_connector[_head_chunk].first.first;
                _chunk_connector[_head_chunk].first.second = -1;
                delete[] _chunk_connector[to_delete].second
            }
            return data;
        }

        T pop_front() {
            
        }
            
        void dump() {
            int curr_node = _rear_node+1,
                curr_chunk = _rear_chunk; 
            cout << "------------------" << endl;
            cout << "_rear_chunk = " << _rear_chunk << endl;
            cout << "_head_chunk = " << _head_chunk << endl;
            cout << "_rear_node = " << _rear_node << endl;
            cout << "_head_node = " << _head_node << endl;
            cout << "------------------" << endl;
            while (curr_chunk != _head_chunk || curr_node != _head_node) {
                cout << "\"" << (_chunk_connector[curr_chunk].second)[curr_node++] << "\" ";
                if (curr_node >= DATA_CHUNK_SIZE - 1) {
                    if (_chunk_connector[curr_chunk].first.second == -1) break;
                    curr_node = 0;
                    curr_chunk = _chunk_connector[curr_chunk].first.second;
                    cout << endl;
                }
            }
            cout << endl << "------------------" << endl;
        }

        ~dequeue() {
            int limit = _chunk_connector.size();
            for (int i=0; i<limit; ++i)
                delete _chunk_connector[i].second;
        };
};

}

using namespace KT;

int main()
{
  dequeue<int> a;
  a.dump();
  return 0;
}
