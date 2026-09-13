#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main () {
	int nums[100000];
	int n = 0;
	bool res = false;

	scanf("%d", &n);
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}

		bool changed = false;
		for (int i = 0; i < n-1; i++) {
			changed = false;
			for (int j = 0; j < (n-i-1); j++) {
				if (nums[j] > nums[j+1]) {
					int tmp = nums[j+1];
					nums[j+1] = nums[j];
					nums[j] = tmp;
					changed = true;
					res = !res;
				}
			}

			if (!changed) i=n;
		}
		
		if (res) printf("Marcelo\n");
		else printf("Carlos\n");
		n = 0;
		res = false;
	
		scanf("%d", &n);
	}

	return 0;
}
