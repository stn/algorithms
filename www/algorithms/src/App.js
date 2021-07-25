import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link,
  useRouteMatch,
  useParams
} from "react-router-dom"; 
import "./sorting/BubbleSort";

function App() {
  return (
    <Router>
      <div className="App">
        <ul>
          <li>
            <Link to="/sorting/bubble">Bubble Sort</Link>
          </li>
          <li>
            Insertion Sort
          </li>
          <li>
            Quick Sort
          </li>
          <li>
            Selection Sort
          </li>
          <li>
            Shaker Sort
          </li>
          <li>
            Shell Sort
          </li>
        </ul>

        <Switch>
          <Route path="/sorting/bubble">
            <BubbleSort />
          </Route>
          <Route path="/">
            <Home />
          </Route>
        </Switch>
      </div>
    </Router>
  );
}

function Home() {
  return <h2>Home</h2>;
}

function BubbleSort() {
  return <h2>Bubble Sort</h2>
}

export default App;
