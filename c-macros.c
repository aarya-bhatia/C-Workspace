#include <stdio.h>
#include <stdarg.h>

#define PRINT(format, ...) printf(format, __VA_ARGS__)

#define LIST_NODE(DATA_CLASS) \
	struct                    \
	{                         \
		DATA_CLASS data;      \
		void *next;           \
	}

typedef LIST_NODE(int) int_node_t;

#define FOREACH(Type, itr, head) for (Type *itr = head; itr; itr = itr->next)

int main()
{
	int_node_t head = {0, NULL};

	// LIST_FOR (itr, (void *)&i1){
	// 	int x = *(int *)itr;
	// }

	FOREACH(int_node_t, current, &head){
		printf("%d\n", current->data);
	}

	return 0;
}
