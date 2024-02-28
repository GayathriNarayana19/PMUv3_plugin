#ifndef PMUV3_INCLUDES_H_BUNDLE
/*
 * Performance Monitoring accessing PMUV3 counters
 * Author: Gayathri  Narayana Yegna Narayanan (gayathrinarayana.yegnanarayanan@arm.com)
 * Description: This plugin supports the initialization of performance monitoring for specific hardware events, reads cycle counts and cleans up the resources after that)
 */
#define PMUV3_INCLUDES_H_BUNDLE

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <linux/perf_event.h>
#include <perf/cpumap.h>
#include <perf/threadmap.h>
#include <perf/evsel.h>
#include <internal/tests.h>
#include <sys/mman.h>
#include <time.h>
#include <inttypes.h> // Include inttypes.h for PRIu64 macro
#include <asm/unistd.h>
#include <stdint.h>
#include <linux/kernel.h>
#include <unistd.h> // For sleep functionality in C
//#include "pmuv3.h"
struct Event {
    const char *event_name;
    uint8_t event_value; 
    // Add other fields as needed
};
struct PerfData{
    struct perf_evsel *global_evsel_0;
    struct perf_evsel *global_evsel_1;
    struct perf_evsel *global_evsel_2;
    struct perf_evsel *global_evsel_3;
    struct perf_evsel *global_evsel_4;
    struct perf_evsel *global_evsel_5;
    struct perf_evsel *global_evsel_6;
    struct perf_evsel *global_evsel_7;
    struct perf_evsel *global_evsel_8;
};
extern struct PerfData *perf_data;

extern struct perf_thread_map *global_threads;
struct CountData{
    struct perf_counts_values global_count_0;
    struct perf_counts_values global_count_1;
    struct perf_counts_values global_count_2;
    struct perf_counts_values global_count_3;
    struct perf_counts_values global_count_4;
    struct perf_counts_values global_count_5;
    struct perf_counts_values global_count_6;
    struct perf_counts_values global_count_7;
    struct perf_counts_values global_count_8;
};
extern struct CountData count_data;
//extern struct perf_evsel *global_evsel;
//extern struct perf_thread_map *global_threads;
//extern struct perf_counts_values global_counts;
#define MAX_EVENTS 8
extern uint64_t num_events; 
extern int *event_values;
extern char **event_names;
//extern struct perf_evsel *global_evsel[MAX_EVENTS];
extern struct perf_thread_map *global_threads;
//extern struct perf_counts_values global_counts[MAX_EVENTS];
extern uint64_t start_0,start_1,start_2,start_3,start_4,start_5,start_6,start_7;
extern uint64_t end_0,end_1,end_2,end_3,end_4,end_5,end_6,end_7;
extern uint64_t eventnum;
//extern int event_names[];
// Function declarations
//int test_stat_user_read(int event);
int test_stat_user_read(int events[]);
int libperf_print_(enum libperf_print_level level, const char *fmt, va_list ap); //to resolve multiple definition linker error 

// Bundle Groups
typedef const struct{
    const char *name;
    uint8_t event_value;
}bundles; 

bundles bundle0[] = {
    {"CPU_CYCLES", 0x11},
    {"L1D_TLB_REFILL", 0x05},
    {"L1D_TLB", 0x25},
    {"L2D_TLB_REFILL", 0x2D},
    {"L2D_TLB", 0x2F},
    {"DTLB_WALK", 0x34}
};

bundles bundle1[] = {
    {"CPU_CYCLES", 0x11},
    /*{"L1D_TLB_REFILL_RD", 0x4C},
    {"L1D_TLB_REFILL_WR", 0x4D},
    {"L1D_TLB_RD", 0x4E},
    {"L1D_TLB_WR", 0x4F},*/
    {"L2D_TLB_REFILL_RD", 0x5C},
    {"L2D_TLB_REFILL_WR", 0x5D},
    {"L2D_TLB_RD", 0x5E},
    {"L2D_TLB_WR", 0x5F}
};

bundles bundle2[] = {
    {"CPU_CYCLES", 0x11},
    {"MEM_ACCESS", 0x13},
    {"BUS_ACCESS", 0x19},
    {"MEMORY_ERROR", 0x1A}
};

bundles bundle3[] = {
    {"CPU_CYCLES", 0x11},
    {"BR_MIS_PRED", 0x10},
    {"BR_PRED", 0x12},
    {"BR_RETIRED", 0x21},
    {"BR_MIS_PRED_RETIRED", 0x22},
    {"BR_IMMED_SPEC", 0x78},
    //{"BR_RETURN_SPEC", 0x79},
    {"BR_INDIRECT_SPEC", 0x7A}
};

bundles bundle4[] = {
    {"CPU_CYCLES", 0x11},
    {"STALL_FRONTEND", 0x23},
    {"STALL_BACKEND", 0x24}
};

bundles bundle5[] = {
    {"CPU_CYCLES", 0x11},
    {"L1I_CACHE_REFILL", 0x01},
    {"L1I_CACHE", 0x14}
};

bundles bundle6[] = {
    {"CPU_CYCLES", 0x11},
    {"L1D_CACHE_REFILL", 0x03},
    {"L1D_CACHE", 0x04},
    {"L2D_CACHE", 0x16},
    {"L2D_CACHE_REFILL", 0x17},
    {"L3D_CACHE_REFILL", 0x2A},
    {"L3D_CACHE", 0x2B},
};

bundles bundle7[] = {
    {"CPU_CYCLES", 0x11},
    {"L1I_TLB_REFILL", 0x02},
    {"L1I_TLB", 0x26},
    {"ITLB_WALK", 0x35}
};

bundles bundle8[] = {
    {"CPU_CYCLES", 0x11},
    {"INST_RETIRED", 0x08}
};

bundles bundle9[] = {
     {"CPU_CYCLES", 0x11},
     {"BR_RETURN_SPEC", 0x79},
};

bundles bundle10[] = {
    {"CPU_CYCLES", 0x11},
    {"L1D_TLB_REFILL_RD", 0x4C},
    {"L1D_TLB_REFILL_WR", 0x4D},
    {"L1D_TLB_RD", 0x4E},
    {"L1D_TLB_WR", 0x4F},
};
#endif // PMUV3_INCLUDES_H_BUNDLE