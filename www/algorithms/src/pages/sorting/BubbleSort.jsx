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
        { x: 8, y: 2.6655117331609333 },
        { x: 16, y: 2.680736611092976 },
        { x: 32, y: 2.927352926435051 },
        { x: 64, y: 4.089827270788441 },
        { x: 128, y: 8.044421308347985 },
        { x: 256, y: 23.291348303358422 },
        { x: 512, y: 82.04195315230135 },
        { x: 1024, y: 316.41517857142514 },
        { x: 2048, y: 1274.2679509631428 },
        { x: 4096, y: 4654.5337837836205 },
        { x: 8192, y: 17031.024390244016 },
        { x: 16384, y: 67927.18181818152 },
        { x: 32768, y: 266376.5000000033 },
      ],
      backgroundColor: 'rgba(255, 99, 132)',
      borderColor: 'rgba(255, 99, 132, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_BubbleSortDesc',
      data: [
        { x: 8, y: 2.5764250488531166 },
        { x: 16, y: 2.6366065919304305 },
        { x: 32, y: 2.93472999162892 },
        { x: 64, y: 4.105562620141231 },
        { x: 128, y: 8.531847732133807 },
        { x: 256, y: 26.665259394516966 },
        { x: 512, y: 97.19388038939147 },
        { x: 1024, y: 377.4168937328599 },
        { x: 2048, y: 1494.802173913202 },
        { x: 4096, y: 5908.367521367321 },
        { x: 8192, y: 22739.700000000343 },
        { x: 16384, y: 91108.71428571343 },
        { x: 32768, y: 363757.0000000068 },
      ],
      backgroundColor: 'rgba(54, 162, 235)',
      borderColor: 'rgba(54, 162, 235, 0.2)',
      showLine: true,
    },
    {
      label: 'BM_BubbleSortRandom',
      data: [
        { x: 8, y: 2.712419859961668 },
        { x: 16, y: 2.941108076331869 },
        { x: 32, y: 3.8709463271971374 },
        { x: 64, y: 6.768031286586838 },
        { x: 128, y: 17.08106024821168 },
        { x: 256, y: 51.414271167916155 },
        { x: 512, y: 157.9434612732727 },
        { x: 1024, y: 546.442675159151 },
        { x: 2048, y: 2096.982035928146 },
        { x: 4096, y: 10067.09859155033 },
        { x: 8192, y: 52260.166666669036 },
        { x: 16384, y: 261522.33333333186 },
        { x: 32768, y: 1188052.9999999965 },
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
