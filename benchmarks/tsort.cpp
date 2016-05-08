#define MAX 1000001
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
int ar[1000000];
    inline void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void insertion_sort(int ar[], int lo, int hi){
        for(int i = lo+1;i<=hi;i++){
            int cur = ar[i];
            int j = i-1;
            while(ar[j] > cur && j >= lo){
                ar[j+1] = ar[j];
                j--;
            }
            ar[j+1] = cur;
        }
    }
    int partition(int ar[], int lo, int hi){
        int i = lo;
        int j = hi+1;
        while(true){
            while(ar[++i] < ar[lo]){
                if(i > hi)
                    break;
            }
            while(ar[lo] < ar[--j]);
            if(i >= j)
                break;
            swap(&ar[i], &ar[j]);
        }
        swap(&ar[lo], &ar[j]);
        return j;
    }
    void sub(int ar[], int lo, int hi){
        int diff = hi - lo;
        if(diff){
            if(diff < 8){
                insertion_sort(ar, lo, hi);
                return;
            }
            int j = partition(ar, lo, hi);
            sub(ar, lo, j-1);
            sub(ar, j+1, hi);
        }
    }
    void sort(int ar[], int size){
        sub(ar, 0, size-1);
    }

int main(){
	int i;
	int n;
	n = fi.ReadNext();
	for(i=0;i<n;i++){
		ar[i] = fi.ReadNext();
	}
	sort(ar,n);
	for(i=0;i<n;i++){
		fo.PrintUint(ar[i],'\n');
	}
	fo.Flush();
	return 0;
} 
