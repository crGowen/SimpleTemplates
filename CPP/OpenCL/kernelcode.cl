void kernel test_func(global int* A, global int* B)
{
	A[get_global_id(0)] = get_group_id(0);
	B[get_global_id(0)] = get_local_id(0);
}