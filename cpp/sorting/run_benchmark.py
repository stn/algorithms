import os
import subprocess
import sys


BENCHMARKS = [
    'bubble_sort_benchmark',
    'bubble_sort_benchmark2',
    'bubble_sort_benchmark3',
#    'insertion_sort_benchmark',
#    'insertion_sort_benchmark2',
#    'insertion_sort_benchmark3',
#    'quick_sort_benchmark',
#    'quick_sort_benchmark2',
#    'quick_sort_benchmark3',
#    'selection_sort_benchmark',
#    'shaker_sort_benchmark',
#    'shell_sort_benchmark',
]

def run_benchmark():
    cwd = os.getcwd()
    for benchmark in BENCHMARKS:
        cmd = 'bazel run //sorting:{0} --compilation_mode=opt -- --benchmark_out={1}/{0}.json --benchmark_out_format=json'.format(benchmark, cwd)
        print(cmd)
        subprocess.run(cmd, shell=True)


def main(argv):
    run_benchmark()


if __name__ == '__main__':
    main(sys.argv)
