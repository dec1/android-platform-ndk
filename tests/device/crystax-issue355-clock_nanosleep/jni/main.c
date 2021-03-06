#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    struct timespec ts1, ts2;
    int rc;
    int64_t diff;

    if (clock_gettime(CLOCK_REALTIME, &ts1) != 0) {
        printf("clock_gettime() failed: %s\n", strerror(errno));
        return 1;
    }

    ts1.tv_sec = 2;

    rc = clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &ts1, NULL);
    if (rc != 0) {
        printf("clock_nanosleep() failed: %s\n", strerror(rc));
        return 1;
    }

    if (clock_gettime(CLOCK_REALTIME, &ts2) != 0) {
        printf("clock_gettime() failed: %s\n", strerror(errno));
        return 1;
    }

    diff = (((int64_t)ts2.tv_sec)*1000000000LL + ts2.tv_nsec) - (((int64_t)ts1.tv_sec)*1000000000LL + ts1.tv_nsec);
    if (diff < 0) {
        printf("clock_nanosleep() sleep slept negative time: diff=%" PRId64 "\n", diff);
        return 1;
    }

    return 0;
}
