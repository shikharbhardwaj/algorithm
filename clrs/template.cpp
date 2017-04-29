#include <atomic>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <thread>
#include <vector>
#include <chrono>


std::atomic<uint64_t> sum_duration_ns{ 0 };

enum { size = 32 * 32 };

char* source = new char[ size ];
char* target = new char[ size ];

void start_thread( int num_threads, int thread_index )
{
	auto per_thread_size = size / (num_threads);
	auto threadtarget = target + (per_thread_size * thread_index);
	auto threadsource = source + (per_thread_size * thread_index);

	auto start_time = std::chrono::high_resolution_clock::now();

	std::memcpy( threadtarget, threadsource, per_thread_size );

	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start_time).count();

	sum_duration_ns += elapsed_ns;
}


void run( long num_threads )
{
	std::vector<std::thread> threads;
	threads.reserve( num_threads );
	sum_duration_ns = 0;

	for ( auto i = 0; i <= num_threads; ++i )
	{
		threads.emplace_back( start_thread, num_threads, i );
	}

	for ( auto& t : threads ) t.join();

	std::cout
	<< "num-threads: " << num_threads
	<< ". throughput: " << long(10.0 * size / sum_duration_ns) / 10.0 << " bytes/ns"
	<< std::endl;
}


int main() {
	for (auto i = 1; i <= 2; ++i) {
		std::memset(source, rand(), size);
		std::memset(target, rand(), size);
		run(i);
	}

	return target[ 0 ];
}
