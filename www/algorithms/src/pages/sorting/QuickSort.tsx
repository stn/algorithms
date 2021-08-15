import React from 'react'
import { Scatter } from 'react-chartjs-2'

import Markdown from '../../components/Markdown'

const data = {
  datasets: [
    {
      label: 'BM_QuickSortRandom',
      data: [
        { x: 8, y: 0.3563784045421372 },
        { x: 16, y: 0.49849372381560225 },
        { x: 32, y: 0.7999083026073999 },
        { x: 64, y: 1.475973747396038 },
        { x: 128, y: 2.9680132874708334 },
        { x: 256, y: 6.272594703562997 },
        { x: 512, y: 13.500715868790772 },
        { x: 1024, y: 29.081840169589356 },
        { x: 2048, y: 62.564421019730844 },
        { x: 4096, y: 134.76741665076307 },
        { x: 8192, y: 287.8089601150669 },
        { x: 16384, y: 611.5163446774369 },
        { x: 32768, y: 1295.453312267755 },
      ],
      backgroundColor: 'rgba(255, 206, 86)',
      borderColor: 'rgba(255, 206, 86, 0.2)',
      showLine: true,
    },
  ],
  options: {
    responsive: true,
  },
}

const data2 = {
  datasets: [
    {
      label: 'BM_QuickSortAsc',
      data: [
        { x: 8, y: 0.31531245180550865 },
        { x: 16, y: 0.3984293832439028 },
        { x: 32, y: 0.7900618358138415 },
        { x: 64, y: 1.786786209713596 },
        { x: 128, y: 4.855618844781754 },
        { x: 256, y: 15.65784107760599 },
        { x: 512, y: 56.15192698130089 },
        { x: 1024, y: 213.96933616244155 },
        { x: 2048, y: 824.2162391048867 },
        { x: 4096, y: 3255.7217777778005 },
        { x: 8192, y: 12906.950240740598 },
        { x: 16384, y: 51491.45028571426 },
        { x: 32768, y: 205669.92999999973 },
      ],
      backgroundColor: 'rgba(255, 99, 132)',
      borderColor: 'rgba(255, 99, 132, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_QuickSortDesc',
      data: [
        { x: 8, y: 0.31340647801133825 },
        { x: 16, y: 0.37371274724341247 },
        { x: 32, y: 0.5483757953960785 },
        { x: 64, y: 1.4352735141576587 },
        { x: 128, y: 4.093266797802933 },
        { x: 256, y: 13.525116026673267 },
        { x: 512, y: 48.696956029458505 },
        { x: 1024, y: 184.6491607853831 },
        { x: 2048, y: 719.2790653527089 },
        { x: 4096, y: 2843.2621504066447 },
        { x: 8192, y: 11474.409899999986 },
        { x: 16384, y: 46123.591733333786 },
        { x: 32768, y: 184573.59750000003 },
      ],
      backgroundColor: 'rgba(54, 162, 235)',
      borderColor: 'rgba(54, 162, 235, 0.2)',
      showLine: true,
    },
  ],
  options: {
    responsive: true,
  },
}

function QuickSort() {
  return (
    <>
      <h2>Quick Sort</h2>
      <div>
        <Markdown>{`

~~~c++
int partition(int* arr, int l, int r) {
  int i = l - 1;
  int j = r;
  int v = arr[r];
  while (true) {
      while (arr[++i] < v);
      while (v < arr[--j]) {
          if (j == l) break;
      }
      if (i >= j) break;
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
  }
  arr[r] = arr[i];
  arr[i] = v;
  return i;
}

void quick_sort_sub(int *arr, int l, int r) {
  if (r <= l) return;
  int i = partition(arr, l, r);
  quick_sort_sub(arr, l, i - 1);
  quick_sort_sub(arr, i + 1, r);
}

void quick_sort(int *arr, int n) {
  quick_sort_sub(arr, 0, n - 1);
}
~~~

        `}</Markdown>
        <Scatter data={data} />

        <Markdown>{`
グラフの形は$O(n)$に近い形となる。実際には$O(n \\log n)$。

しかし、上記のquick sortは元から整列していた配列や、逆順の配列の場合、最悪の計算量$O(n^2)$となる。
        `}</Markdown>
        <Scatter data={data2} />
      </div>
    </>
  )
}

export default QuickSort
