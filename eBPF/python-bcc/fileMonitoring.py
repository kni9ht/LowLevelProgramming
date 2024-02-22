from bcc import BPF

program = """
#include <linux/ptrace.h>
#include <linux/fs.h>

BPF_PERF_OUTPUT(events);

struct data_t {
    u64 timestamp;
    char filename[256];
};

TRACEPOINT_PROBE(syscalls, sys_enter_open)
{
    struct data_t data = {};
    data.timestamp = bpf_ktime_get_ns();
    bpf_probe_read(&data.filename, sizeof(data.filename), args->filename);
    events.perf_submit(args, &data, sizeof(data));
    return 0;
}
"""

bpf = BPF(text=program)

print("Monitoring file opens... Press Ctrl+C to exit.")

def print_filename(cpu, data, size):
    event = bpf["events"].event(data)
    filename = event.filename.decode("utf-8")
    print(f"File opened: {filename}")

bpf["events"].open_perf_buffer(print_filename)

try:
    while True:
        bpf.perf_buffer_poll()
except KeyboardInterrupt:
    pass

print("Exiting...")