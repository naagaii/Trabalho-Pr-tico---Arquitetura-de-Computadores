#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "read_csv.c"
#include "normalize_vector.c"

void get_resource_usage(struct rusage* usage) {
    getrusage(RUSAGE_SELF, usage);
}

void print_resource_usage(const char* label, struct rusage* usage) {
    printf("%s\n", label);
    printf("User time: %ld.%06ld seconds\n", usage->ru_utime.tv_sec, usage->ru_utime.tv_usec);
    printf("System time: %ld.%06ld seconds\n", usage->ru_stime.tv_sec, usage->ru_stime.tv_usec);
    printf("Maximum resident set size: %ld kilobytes\n", usage->ru_maxrss);
}

int main() {
    int num_elements, num_dimensions;
    float** features = read_csv("data/data.csv", &num_elements, &num_dimensions);

    struct rusage start_usage, end_usage;

    get_resource_usage(&start_usage);
    for (int i = 0; i < num_elements; i++) {
        normalize_naive(features[i], num_dimensions);
    }
    get_resource_usage(&end_usage);

    print_resource_usage("Execution Time:", &start_usage);
    print_resource_usage("End Usage:", &end_usage);

    // Libera a memória
    for (int i = 0; i < num_elements; i++) {
        free(features[i]);
    }
    free(features);
    return 0;
}
