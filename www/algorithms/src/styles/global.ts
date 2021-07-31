import { css } from '@linaria/core'

const ress = require('./ress.css') as string
const indexcss = require('./index.css') as string

export const globals = css`
  :global() {
    ${ress}
    ${indexcss}
  }
`
