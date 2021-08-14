import React from 'react'
import ReactMarkdown from 'react-markdown'
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter'
import { vs } from 'react-syntax-highlighter/dist/esm/styles/prism'
import remarkMath from 'remark-math'
import rehypeKatex from 'rehype-katex'
import 'katex/dist/katex.min.css' // `rehype-katex` does not import the CSS for you
import { Scatter } from 'react-chartjs-2'

import Markdown from '../../components/Markdown'

const labels = []
for (let i = 0; i < 90000; i += 10000) {
  labels.push(i.toString())
}
const data = {
  datasets: [
    {
      label: 'BM_BubbleSortAsc',
      data: [
        { x: 8, y: 0.28931588822904497 },
        { x: 16, y: 0.37215892833287134 },
        { x: 32, y: 0.6992472774687621 },
        { x: 64, y: 1.866804630401268 },
        { x: 128, y: 6.340108354774167 },
        { x: 256, y: 23.882599693194432 },
        { x: 512, y: 93.34326810826563 },
        { x: 1024, y: 369.4586335272473 },
        { x: 2048, y: 1485.5935074309577 },
        { x: 4096, y: 5875.853605042101 },
        { x: 8192, y: 23491.380533333424 },
        { x: 16384, y: 92945.04542857142 },
        { x: 32768, y: 373812.7594999998 },
      ],
      backgroundColor: 'rgba(255, 99, 132)',
      borderColor: 'rgba(255, 99, 132, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_BubbleSortDesc',
      data: [
        { x: 8, y: 0.28827375495690516 },
        { x: 16, y: 0.3320854304470427 },
        { x: 32, y: 0.5601463619067455 },
        { x: 64, y: 1.5201651139181447 },
        { x: 128, y: 5.896427223856983 },
        { x: 256, y: 26.124897308594075 },
        { x: 512, y: 110.85082120251657 },
        { x: 1024, y: 456.6675778502313 },
        { x: 2048, y: 1849.116053333347 },
        { x: 4096, y: 7468.121170212896 },
        { x: 8192, y: 30030.158260869684 },
        { x: 16384, y: 120727.28616666712 },
        { x: 32768, y: 482607.16699999763 },
      ],
      backgroundColor: 'rgba(54, 162, 235)',
      borderColor: 'rgba(54, 162, 235, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_BubbleSortRandom',
      data: [
        { x: 8, y: 0.3397984178365679 },
        { x: 16, y: 0.5570621646576436 },
        { x: 32, y: 1.2860527534745603 },
        { x: 64, y: 3.8845156591782914 },
        { x: 128, y: 13.201557994501393 },
        { x: 256, y: 42.085980531624784 },
        { x: 512, y: 140.34673096941665 },
        { x: 1024, y: 504.51617268799055 },
        { x: 2048, y: 1975.9384378530747 },
        { x: 4096, y: 9189.690727272258 },
        { x: 8192, y: 46755.86793333319 },
        { x: 16384, y: 220406.7620000032 },
        { x: 32768, y: 956759.9030000054 },
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

function BubbleSort() {
  return (
    <>
      <h2>Bubble Sort</h2>
      <div>
        <Markdown>{`
簡単に理解できるということでよく最初に習うソート。

気持ちとしては、順序が前後しているところを入れ替えるという操作を、そういったところがなくなるまで続ければ全体がソートされるよねということ。

順序が前後しているところを配列の前から順に探すと、結果として一番大きな要素が一番後ろに移動する。（逆に後ろからみていくと、一番小さな要素が先頭に移動する。）

1. 最初の２つの要素を比較して、順序がおかしければ（前の方が後ろのものより大きければ）入れ替える。
1. 次に、一つ後ろに移動してこれを繰り返す。つまり、2番目と3番目の要素に対して、1の操作を行う。これを一つづつ後ろに移動しながら、一番、最後まで続ける。
1. 最後までたどり着いたら、1へ戻る。ただし、最後の要素はすでに最大のものになっているので、その一つ前で終了する。

最悪ケースの計算量は $O(n^2)$ 。

安定ソートであり、並列化も考えやすい。

~~~c++
void bubble_sort(int *arr, int n) {
  for (int i = 0; i < n - 1; ++i) {
      for (int j = n - 1; j > i; --j) {
          if (arr[j - 1] > arr[j]) {
              int tmp = arr[j];
              arr[j] = arr[j - 1];
              arr[j - 1] = tmp;
          }
      }
  }
}
~~~

bubble sortは揃っていない部分を必ず入れ替えるので、一度も入れ替えが起きなかったときは処理を終えてよい。
しかし、そのチェックを入れるとループ内の処理が増えるために、ランダムのときはかえって処理が遅くなる。 (bubble_sort2/cpp)
        `}</Markdown>
      </div>
      <Scatter data={data} />
    </>
  )
}

export default BubbleSort
