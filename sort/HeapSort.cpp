class minHeap{
    public:
        minHeap(vector<int> vec){
        heap.resize(vec.size() + 1, 0);
        for(int i = 0; i < vec.size(); i++){
            heap[i+1] = vec[i];
        }
        size =  vec.size();
        for(int i = (size+1)/2; i >= 1; i--){
            minHeapify(i);
        }
    }
        vector<int> heap;
        int size;

    void minHeapify(int i){
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;
        if(left <= size && heap[left] < heap[i])
            smallest = left;
        if(right <= size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i){
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }

    void heapSort(){
        int temp = size;
        for(int i = size; i >= 2; i--){
            swap(heap[i], heap[1]);
            size--;
            minHeapify(1);
        }
        size = temp;
    }
    void print(){
        for(int i = 1; i <= size; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    //heapsort
    vec = {3 ,5 ,1, 2, 4, -1, -3};
    minHeap _minHeap = minHeap(vec);
    _minHeap.heapSort();
    _minHeap.print();

}
