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
    <>
      <AppHeader />
      <Container className="clearfix">
        <Router>
          <AppMain>
            <Switch>
              <Route path="/sorting/bubble">
                <BubbleSort />
              </Route>
              <Route path="/">
                <div>Home</div>
              </Route>
            </Switch>
          </AppMain>
          <SideMenu>
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
          </SideMenu>
        </Router>
      </Container>
      <AppFooter />
    </>
  )
}

const Container = styled.div`
  width: 970px;
  margin: 30px auto 40px;
`

const SideMenu = styled.div`
  float: left;
  width: 275px;
`

const AppMain = styled.div`
  display: block;
  float: right;
  width: 660px;
`

const AppHeader = styled.header`
  width: 100%;
`

const AppFooter = styled.footer`
  width: 100%;
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
