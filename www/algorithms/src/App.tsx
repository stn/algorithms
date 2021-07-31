import React from 'react'
import { styled } from '@linaria/react'
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link,
  useRouteMatch,
  useParams,
} from 'react-router-dom'
import BubbleSort from './sorting/BubbleSort'

const logo = require('./logo.svg') as string

const App: React.FC = () => {
  return (
    <Router>
      <div>
        <ul>
          <li>
            <Link to="/sorting/bubble">Bubble Sort</Link>
          </li>
          <li>Insertion Sort</li>
          <li>Quick Sort</li>
          <li>Selection Sort</li>
          <li>Shaker Sort</li>
          <li>Shell Sort</li>
        </ul>

        <Switch>
          <Route path="/sorting/bubble">
            <BubbleSort />
          </Route>
          <Route path="/">
            <div>Home</div>
          </Route>
        </Switch>
      </div>
    </Router>
  )
}

const Container = styled.div`
  text-align: center;
`

const AppHeader = styled.header`
  background-color: #282c34;
  min-height: 100vh;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  font-size: calc(10px + 2vmin);
  color: white;
`

const Img = styled.img`
  height: 40vmin;
  pointer-events: none;
  @media (prefers-reduced-motion: no-preference) {
    animation: App-logo-spin infinite 20s linear;
  }
  @keyframes App-logo-spin {
    from {
      transform: rotate(0deg);
    }
    to {
      transform: rotate(360deg);
    }
  }
`

const Paragraph = styled.p``

export default App
