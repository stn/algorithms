import React from 'react'
import { Scatter } from 'react-chartjs-2'

import Markdown from '../../components/Markdown'

const data = {
  datasets: [
    {
      label: 'BM_ShakerSortAsc',
      data: [
        { x: 8, y: 0.27957026347693725 },
        { x: 16, y: 0.28476990114048123 },
        { x: 32, y: 0.2955039710597844 },
        { x: 64, y: 0.321218822704011 },
        { x: 128, y: 0.36388334197226385 },
        { x: 256, y: 0.4509287261957552 },
        { x: 512, y: 0.6278341393949571 },
        { x: 1024, y: 0.977243707242879 },
        { x: 2048, y: 1.640819614422941 },
        { x: 4096, y: 3.05324571917176 },
        { x: 8192, y: 5.760530409162464 },
        { x: 16384, y: 11.215802174100718 },
        { x: 32768, y: 22.108069415752475 },
      ],
      backgroundColor: 'rgba(255, 99, 132)',
      borderColor: 'rgba(255, 99, 132, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_ShakerSortDesc',
      data: [
        { x: 8, y: 0.2915667566681967 },
        { x: 16, y: 0.336842112269679 },
        { x: 32, y: 0.5322503849964215 },
        { x: 64, y: 1.458263652505988 },
        { x: 128, y: 5.962182532903655 },
        { x: 256, y: 26.6445884751736 },
        { x: 512, y: 111.70542300944156 },
        { x: 1024, y: 457.9820588619863 },
        { x: 2048, y: 1862.9332625993763 },
        { x: 4096, y: 7506.069473118217 },
        { x: 8192, y: 30103.566956521045 },
        { x: 16384, y: 120806.33550000167 },
        { x: 32768, y: 483859.6795000001 },
      ],
      backgroundColor: 'rgba(54, 162, 235)',
      borderColor: 'rgba(54, 162, 235, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_ShakerSortRandom',
      data: [
        { x: 8, y: 0.33715867009416073 },
        { x: 16, y: 0.5003816069998805 },
        { x: 32, y: 1.0340752497074137 },
        { x: 64, y: 2.9244709161828726 },
        { x: 128, y: 9.382370556996635 },
        { x: 256, y: 31.204292267179113 },
        { x: 512, y: 105.41959981993654 },
        { x: 1024, y: 374.77211821094124 },
        { x: 2048, y: 1429.460879837416 },
        { x: 4096, y: 6349.535027272358 },
        { x: 8192, y: 32420.108545454437 },
        { x: 16384, y: 156137.32539999744 },
        { x: 32768, y: 675413.3059999958 },
      ],
      backgroundColor: 'rgba(255, 206, 86)',
      borderColor: 'rgba(255, 206, 86, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_BubbleSort2Random',
      data: [
        { x: 8, y: 0.3404872026359434 },
        { x: 16, y: 0.5578101409799994 },
        { x: 32, y: 1.2849032783984196 },
        { x: 64, y: 3.878451352701232 },
        { x: 128, y: 13.129458697320322 },
        { x: 256, y: 41.99057520167057 },
        { x: 512, y: 140.14439396991654 },
        { x: 1024, y: 503.04871684597515 },
        { x: 2048, y: 1972.9789185392056 },
        { x: 4096, y: 9133.877220779252 },
        { x: 8192, y: 46391.51686666452 },
        { x: 16384, y: 218948.17699999906 },
        { x: 32768, y: 951574.9569999983 },
      ],
      backgroundColor: 'rgba(75, 192, 192)',
      borderColor: 'rgba(75, 192, 192, 0.2)',
      showLine: true,
    },
  ],
  options: {
    responsive: true,
  },
}

function ShakerSort() {
  return (
    <>
      <h2>Shaker Sort</h2>
      <div>
        <Markdown>{`
Bubble sortを行う方向を毎回、左から右へと右から左へを入れ替えるものをShaker Sortという。

~~~c++
void shaker_sort(int *arr, int n) {
  if (n == 0) return;

  int left = 0;
  int right = n - 1;

  while (true) {
      int last = left;

      for (int i = left; i < right; ++i) {
          if (arr[i] > arr[i + 1]) {
              int tmp = arr[i];
              arr[i] = arr[i + 1];
              arr[i + 1] = tmp;
              last = i;
          }
      }
      right = last;

      if (left == right) {
          break;
      }

      for (int i = right; i > left; --i) {
          if (arr[i -1] > arr[i]) {
              int tmp = arr[i];
              arr[i] = arr[i - 1];
              arr[i - 1] = tmp;
              last = i;
          }
      }
      left = last;

      if (left == right) {
          break;
      }
  }
}
~~~

本質的にはbubble sortと変わらないはずのshaker sortがbubble sortよりも速くなる。
これは、CPUキャッシュが効くためだと考えられる。
        `}</Markdown>
        <Scatter data={data} />
      </div>
    </>
  )
}

export default ShakerSort
