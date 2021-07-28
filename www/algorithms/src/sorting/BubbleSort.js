import ReactMarkdown from 'react-markdown'
import {Prism as SyntaxHighlighter} from 'react-syntax-highlighter'
import {vs} from 'react-syntax-highlighter/dist/esm/styles/prism'
import remarkMath from 'remark-math'
import rehypeKatex from 'rehype-katex'
import 'katex/dist/katex.min.css' // `rehype-katex` does not import the CSS for you
import { Scatter } from 'react-chartjs-2';

const components = {
  code({node, inline, className, children, ...props}) {
    const match = /language-(\w+)/.exec(className || '')
    return !inline && match ? (
      <SyntaxHighlighter style={vs} language={match[1]} PreTag="div" children={String(children).replace(/\n$/, '')} {...props} />
    ) : (
      <code className={className} {...props}>
        {children}
      </code>
    )
  }
}

const markdown = `
簡単に理解できるということでよく最初に習うソート。

気持ちとしては、順序が前後しているところを入れ替えるという操作を、そういったところがなくなるまで続ければ全体がソートされるよねということ。

順序が前後しているところを配列の前から順に探すと、結果として一番大きな要素が一番後ろに移動する。（逆に後ろからみていくと、一番小さな要素が先頭に移動する。）

最初の２つの要素を比較して、順序がおかしければ（前の方が後ろのものより大きければ）入れ替える。次に、一つ後ろに移動してこれを繰り返す。
一番、後ろまでいったら、先頭に戻ってこれを繰り返す。ただし、先ほどの最後のものはすでに最大のものになっているので、その一つ前で終了し、先頭に戻る。

最悪ケースの計算量は $O(n^2)$ 。

安定ソートであり、並列化も考えやすい。

~~~python
def bubble_sort(arr):
    for i in range(len(arr) - 1):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1]
    return arr
~~~

bubble sortは揃っていない部分を必ず入れ替えるので、一度も入れ替えが起きなかったときは処理を終えてよい。
しかし、そのチェックを入れるとループ内の処理が増えるために、ランダムのときはかえって処理が遅くなる。 (bubble_sort2/cpp)
`

const labels = [];
for (let i = 0; i < 90000; i += 10000) {
  labels.push(i.toString());
}
const data = {
  datasets: [
    {
      label: 'asc',
      data: [
        { x: 8, y: 2598 },
        { x: 16, y: 2675 },
        { x: 32, y: 2960 },
        { x: 64, y: 4080 },
        { x: 128, y: 7978 },
        { x: 256, y: 23448 },
        { x: 512, y: 80358 },
        { x: 1024, y: 310985 },
        { x: 2048, y: 1212500 },
        { x: 4096, y: 4656872 },
        { x: 8192, y: 17301435 },
        { x: 16384, y: 67409144 },
        { x: 32768, y: 265932125 }
      ],
      showLine: true,
    }
  ],
  options: {
    responsive: true,
  }
}

function BubbleSort() {
  return (<>
    <h2>Bubble Sort</h2>
    <div>
      <ReactMarkdown
        components={components}
        remarkPlugins={[remarkMath]}
        rehypePlugins={[rehypeKatex]}
        children={markdown} />
    </div>
    <Scatter 
      data={data}
    />
  </>);
}

export default BubbleSort;
