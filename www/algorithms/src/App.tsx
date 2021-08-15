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
import BubbleSort from './pages/sorting/BubbleSort'
import InsertionSort from './pages/sorting/InsertionSort'
import SelectionSort from './pages/sorting/SelectionSort'
import ShakerSort from './pages/sorting/ShakerSort'
import ShellSort from './pages/sorting/ShellSort'
import QuickSort from './pages/sorting/QuickSort'

const App: React.FC = () => {
  return (
    <>
      <AppHeader />
      <Container className="clearfix">
        <Router>
          <AppMain>
            <Switch>
              <Route path="/sorting/bubble_sort">
                <BubbleSort />
              </Route>
              <Route path="/sorting/insertion_sort">
                <InsertionSort />
              </Route>
              <Route path="/sorting/quick_sort">
                <QuickSort />
              </Route>
              <Route path="/sorting/selection_sort">
                <SelectionSort />
              </Route>
              <Route path="/sorting/shaker_sort">
                <ShakerSort />
              </Route>
              <Route path="/sorting/shell_sort">
                <ShellSort />
              </Route>
              <Route path="/">
                <div>Home</div>
              </Route>
            </Switch>
          </AppMain>
          <SideMenu>
            <ul>
              <li>
                <Link to="/sorting/bubble_sort">Bubble Sort</Link>
              </li>
              <li>
                <Link to="/sorting/shaker_sort">Shaker Sort</Link>
              </li>
              <li>
                <Link to="/sorting/insertion_sort">Insertion Sort</Link>
              </li>
              <li>
                <Link to="/sorting/selection_sort">Selection Sort</Link>
              </li>
              <li>
                <Link to="/sorting/shell_sort">Shell Sort</Link>
              </li>
              <li>
                <Link to="/sorting/quick_sort">Quick Sort</Link>
              </li>
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

const Paragraph = styled.p``

export default App
