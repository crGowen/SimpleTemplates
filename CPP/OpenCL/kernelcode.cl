void kernel test_func(global const int* A, global const int* B, global int* C)
{
	printf("PRINTING FROM THE GPU!!!");
	C[get_global_id(0)] = A[get_global_id(0)] + B[get_global_id(0)];
}