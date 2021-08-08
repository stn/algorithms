from collections import defaultdict
import json
import sys

from typing import Dict

COLORS = [
    'rgba(255, 99, 132',
    'rgba(54, 162, 235',
    'rgba(255, 206, 86',
    'rgba(75, 192, 192',
    'rgba(153, 102, 255',
    'rgba(255, 159, 64',
]

def convert_json(df: Dict, filename: str):
    color = 0
    result = defaultdict(lambda: defaultdict(float))
    for b in df['benchmarks']:
        name, x = b['name'].split('/')
        result[name][x] = b['cpu_time'] / 1000.0
    with open(filename, 'w') as f:
        f.write('[\n')
        for k, v in result.items():
            f.write("  {\n")
            f.write("    label: '{}',\n".format(k))
            f.write("    data: [\n")
            for x, y in v.items():
                f.write("      { x: ")
                f.write(str(x))
                f.write(", y: ")
                f.write(str(y))
                f.write(" },\n")
            f.write("    ],\n")
            f.write("    backgroundColor: '{})',\n".format(COLORS[color]))
            f.write("    borderColor: '{}, 0.2)',\n".format(COLORS[color]))
            f.write("    showLine: true,\n")
            f.write("  },\n")
            color = (color + 1) % len(COLORS)
        f.write('],\n')


def main(argv):
    with open(argv[1], 'r') as f:
        df = json.load(f)
    convert_json(df, argv[1].replace('.json', '.data'))


if __name__ == '__main__':
    main(sys.argv)
