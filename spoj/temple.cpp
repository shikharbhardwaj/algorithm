#define MAX 1000001
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
//Introducing faster IO here : 
class FastInput {
public:
	FastInput(){
		m_dataOffset = 0;
		m_dataSize = 0;
		m_v = 0x80000000;
	}
	uint32_t ReadNext() {
		if (m_dataOffset == m_dataSize) {
			int r = read(0, m_buffer, sizeof(m_buffer));
			if (r <= 0) return m_v;
			m_dataOffset = 0;
			m_dataSize = 0;
			int i = 0;
			if (m_buffer[0] < '0') {
				if (m_v != 0x80000000) {
					m_data[m_dataSize++] = m_v;
					m_v = 0x80000000;
				}
				for (; (i < r) && (m_buffer[i] < '0'); ++i);
			}
		for (; i < r;) {
			if (m_buffer[i] >= '0') {
				m_v = m_v * 10 + m_buffer[i] - 48;
				++i;
			} else {
				m_data[m_dataSize++] = m_v;
				m_v = 0x80000000;
				for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
			}
	}
}
return m_data[m_dataOffset++];
}
public:
	uint8_t m_buffer[32768];
	uint32_t m_data[16384];
	size_t m_dataOffset, m_dataSize;
	uint32_t m_v;
};
class FastOutput {
public:
	FastOutput() {
		m_dataOffset = 0;
	}
	~FastOutput() {
	}
	void Flush() {
		if (m_dataOffset) {
			if (write(1, m_data, m_dataOffset)){}
			m_dataOffset = 0;
		}
	}
	void PrintUint(uint32_t v, char d) {
		if (m_dataOffset + 11 > sizeof(m_data)) Flush();
		if (v < 100000) {
			if (v < 1000) {
				if (v < 10) {
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 1;
				} else if (v < 100) {
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 2;
				} else {
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 3;
				}
			} else {
				if (v < 10000) {
					m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 4;
				} else {
					m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 5;
				}
			}
		} else {
			if (v < 100000000) {
				if (v < 1000000) {
					m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 6;
				} else if (v < 10000000) {
					m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 7;
				} else {
					m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 8;
				}
			} else {
				if (v < 1000000000) {
					m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 9;
				} else {
					m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
					m_data[m_dataOffset + 0] = v + 48;
					m_dataOffset += 10;
				}
			}
		}
		m_data[m_dataOffset++] = d;
	}
	void PrintChar(char d) {
		if (m_dataOffset + 1 > sizeof(m_data)) Flush();
		m_data[m_dataOffset++] = d;
	}
	void ReplaceChar(int offset, char d) {
		m_data[m_dataOffset + offset] = d;
	}
public:
	uint8_t m_data[32768];
	size_t m_dataOffset;
};
FastInput fi;		//The input and output streams.
FastOutput fo;
int getSegTreeSize(int in){
    float logVal = log2(in);
    if(logVal == (int)logVal){
        return 2*in;
    }
    return pow(2, (int)logVal + 2);
}
struct segTreeNode{
    int min, max, minSum, maxSum;
    int updateVal;
    bool update;
    segTreeNode() : min(-1), max(-1), minSum(-1), maxSum(-1), updateVal(0), update(false) {}
    void setState(int min, int max, int minSum, int maxSum){
        this->min = min;
        this->max = max;
        this->minSum = minSum;
        this->maxSum = maxSum;
    }
};
segTreeNode tree[262145];
int ar[100005];
int id;
void buildTree(int index, int min, int max){
    tree[index].setState(min, max, 0, 0);
    if(min == max && min != -1){
        tree[index].minSum = tree[index].maxSum = ar[id++];
        return;
    }
    buildTree(2*index, min, (min+max)/2);
    buildTree(2*index+1, (min+max)/2+1, max);
    tree[index].maxSum = std::max(tree[2*index].maxSum , tree[2*index+1].maxSum);
    tree[index].minSum = std::min(tree[2*index].minSum, tree[2*index+1].minSum);
}
void pointUpdate(int index, int in){
    if(tree[index].update){
        tree[index].maxSum = tree[index].maxSum + tree[index].updateVal;
        tree[index].minSum = tree[index].minSum + tree[index].updateVal;
        if(tree[index].min != tree[index].max){
            tree[2*index].update = true;
            tree[2*index].updateVal += tree[index].updateVal;
            tree[2*index+1].update = true;
            tree[2*index+1].updateVal += tree[index].updateVal;
        }
        tree[index].update = false;
        tree[index].updateVal = 0;
    }
    if(tree[index].min > in || tree[index].max < in){
        return;
    }
    else if(tree[index].min == tree[index].max && tree[index].min == in){
        //This is the node to update
        tree[index].maxSum++;
        tree[index].minSum++;
        return;
    }
    if(tree[2*index].max >= in){
        pointUpdate(2*index, in);
    }
    else{
        pointUpdate(2*index+1, in);
    }
    tree[index].maxSum = std::max(tree[2*index].maxSum , tree[2*index+1].maxSum);
    tree[index].minSum = std::min(tree[2*index].minSum, tree[2*index+1].minSum);
}
void rangeUpdate(int index, int in){
    if(tree[index].maxSum == 0 && tree[index].minSum == 0){
        return;
    }
    if(tree[index].update){
        tree[index].maxSum = tree[index].maxSum + tree[index].updateVal;
        tree[index].minSum = tree[index].minSum + tree[index].updateVal;
        if(tree[index].min != tree[index].max){
            tree[2*index].update = true;
            tree[2*index].updateVal += tree[index].updateVal;
            tree[2*index+1].update = true;
            tree[2*index+1].updateVal += tree[index].updateVal;
        }
        tree[index].update = false;
        tree[index].updateVal = 0;
    } if(tree[index].maxSum < in){
        return;
    }
    if(tree[index].minSum >= in){
        tree[index].minSum--;
        tree[index].maxSum--;
        if(tree[index].min != tree[index].max){
            tree[2*index].update = true;
            tree[2*index].updateVal--;
            tree[2*index+1].update = true;
            tree[2*index+1].updateVal--;
        }
        return;
    }
    if(tree[2*index].maxSum >= in){
        rangeUpdate(2*index, in);
    }
    if(tree[2*index+1].maxSum >= in){
        rangeUpdate(2*index+1, in);
    }
    tree[index].maxSum = std::max(tree[2*index].maxSum , tree[2*index+1].maxSum);
    tree[index].minSum = std::min(tree[2*index].minSum, tree[2*index+1].minSum);
}
void query(int index, int in, int &ret){
    if(tree[index].update){
        tree[index].maxSum = tree[index].maxSum + tree[index].updateVal;
        tree[index].minSum = tree[index].minSum + tree[index].updateVal;
        if(tree[index].min != tree[index].max){
            tree[2*index].update = true;
            tree[2*index].updateVal += tree[index].updateVal;
            tree[2*index+1].update = true;
            tree[2*index+1].updateVal += tree[index].updateVal;
        }
        tree[index].update = false;
        tree[index].updateVal = 0;
    }
    if(tree[index].maxSum < in){
        return;
    }
    if(tree[index].minSum >= in){
        ret += tree[index].max - tree[index].min + 1;
        return;
    }
    if(tree[2*index].maxSum >= in){
        query(2*index, in, ret);
    }
    if(tree[2*index+1].maxSum >= in){
        query(2*index+1, in, ret);
    }
}
int main(){
    int N, Q, T, V;
    int S;
    N = fi.ReadNext();
    Q = fi.ReadNext();
    for(int i = 0; i < N; i++){
        ar[i] = fi.ReadNext();
    }
    id = 0;
    buildTree(1, 1, N);
    for(int i = 0; i < Q; i++){
        T = fi.ReadNext();
        V = fi.ReadNext();
        if(T == 1){
            pointUpdate(1, V);
        }
        else if(T == 2){
            S = 0;
            query(1, V, S);
            fo.PrintUint(S,'\n');
        }
        else if(T == 3){
            rangeUpdate(1, V);
        }
        fo.Flush();
    }
}
