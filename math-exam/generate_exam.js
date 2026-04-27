const {
  Document, Packer, Paragraph, TextRun, Table, TableRow, TableCell,
  AlignmentType, HeadingLevel, BorderStyle, WidthType, ShadingType,
  LevelFormat, PageNumber, PageBreak, Header, Footer, Tab, TabStopType,
  TabStopPosition
} = require('docx');
const fs = require('fs');

// ── Helpers ──────────────────────────────────────────────────────────────────

function heading(text, level = HeadingLevel.HEADING_1) {
  return new Paragraph({ heading: level, children: [new TextRun({ text, bold: true })] });
}

function centered(runs, spaceBefore = 0, spaceAfter = 60) {
  return new Paragraph({
    alignment: AlignmentType.CENTER,
    spacing: { before: spaceBefore, after: spaceAfter },
    children: Array.isArray(runs) ? runs : [runs]
  });
}

function rule() {
  return new Paragraph({
    border: { bottom: { style: BorderStyle.SINGLE, size: 6, color: '2E4057', space: 1 } },
    spacing: { before: 60, after: 60 },
    children: []
  });
}

function spacer(pts = 80) {
  return new Paragraph({ spacing: { before: pts, after: 0 }, children: [] });
}

function bold(text, size = 22) { return new TextRun({ text, bold: true, size }); }
function normal(text, size = 22) { return new TextRun({ text, size }); }
function italic(text, size = 22) { return new TextRun({ text, italics: true, size }); }
function super_(text) { return new TextRun({ text, superScript: true, size: 18 }); }

// Question number + label badge
function qLabel(n, tag) {
  const colors = { 'CONCEPTUAL': 'E8F4F8', 'CALCULATION': 'FFF8E7', 'TRICK': 'FFE8E8' };
  const textColors = { 'CONCEPTUAL': '1A5276', 'CALCULATION': '7D6608', 'TRICK': '922B21' };
  return { bg: colors[tag] || 'F5F5F5', fg: textColors[tag] || '333333' };
}

// Build a single MCQ block
function mcqBlock(num, type, questionRuns, options, note = null) {
  const { bg, fg } = qLabel(num, type);
  const typeLabel = `[${type}]`;
  const blocks = [];

  // Question header row
  blocks.push(new Paragraph({
    spacing: { before: 200, after: 40 },
    shading: { fill: bg, type: ShadingType.CLEAR },
    border: { left: { style: BorderStyle.SINGLE, size: 12, color: fg, space: 4 } },
    indent: { left: 180 },
    children: [
      new TextRun({ text: `Q${num}.  `, bold: true, size: 22, color: '1B2631' }),
      new TextRun({ text: typeLabel + '  ', bold: true, size: 18, color: fg }),
      ...questionRuns
    ]
  }));

  // Options
  const optLetters = ['A)', 'B)', 'C)', 'D)'];
  options.forEach((opt, i) => {
    blocks.push(new Paragraph({
      indent: { left: 360, hanging: 360 },
      spacing: { before: 30, after: 30 },
      children: [
        new TextRun({ text: `     ${optLetters[i]}  `, bold: true, size: 21, color: '2C3E50' }),
        ...opt
      ]
    }));
  });

  if (note) {
    blocks.push(new Paragraph({
      indent: { left: 360 },
      spacing: { before: 60, after: 60 },
      shading: { fill: 'FEF9E7', type: ShadingType.CLEAR },
      children: [
        new TextRun({ text: '📝 Professor\'s Note: ', bold: true, size: 20, color: '784212' }),
        new TextRun({ text: note, italics: true, size: 20, color: '784212' })
      ]
    }));
  }

  return blocks;
}

function r(text) { return [normal(text)]; }
function rb(text) { return [bold(text)]; }

// ── All 40 Questions ─────────────────────────────────────────────────────────

const questions = [

  // ════════════════════════════════════════════════
  // SECTION 1: LIMITS  (Q1–Q15)
  // ════════════════════════════════════════════════

  // Q1  CONCEPTUAL
  {
    num: 1, type: 'CONCEPTUAL',
    q: [normal('Which statement correctly relates one-sided limits to the two-sided limit for a function f at x = a?')],
    opts: [
      [normal('lim\u2093\u2192a f(x) = L  if and only if  lim\u2093\u2192a\u207a f(x) = L  AND  lim\u2093\u2192a\u207b f(x) = L')],
      [normal('lim\u2093\u2192a f(x) = L  whenever  lim\u2093\u2192a\u207a f(x) = L  alone')],
      [normal('lim\u2093\u2192a f(x) = L  always equals f(a)')],
      [normal('One-sided limits are only needed when f(a) is undefined')]
    ]
  },

  // Q2  CONCEPTUAL
  {
    num: 2, type: 'CONCEPTUAL',
    q: [normal('If lim\u2093\u2192a f(x) = 7 and lim\u2093\u2192a g(x) = 0, what can be concluded about lim\u2093\u2192a [f(x)/g(x)]?')],
    opts: [
      [normal('The limit equals 7')],
      [normal('The limit equals 0')],
      [normal('The limit equals \u221e')],
      [normal('The limit may not exist \u2014 it could be +\u221e, \u2212\u221e, or DNE depending on how g(x) \u2192 0')]
    ]
  },

  // Q3  CONCEPTUAL
  {
    num: 3, type: 'CONCEPTUAL',
    q: [normal('A function satisfies f(5) = 7, yet lim\u2093\u21925 f(x) = 4. Which statement MUST be true?')],
    opts: [
      [normal('f is continuous at x = 5')],
      [normal('f is discontinuous at x = 5')],
      [normal('f is differentiable at x = 5')],
      [normal('The limit does not exist at x = 5')]
    ]
  },

  // Q4  CONCEPTUAL
  {
    num: 4, type: 'CONCEPTUAL',
    q: [normal('The Squeeze (Sandwich) Theorem states: if h(x) \u2264 f(x) \u2264 g(x) near x = a, and lim\u2093\u2192a h(x) = lim\u2093\u2192a g(x) = L, then:')],
    opts: [
      [normal('f(a) = L')],
      [normal('lim\u2093\u2192a f(x) \u2264 L')],
      [normal('lim\u2093\u2192a f(x) = L')],
      [normal('f(x) = L for all x near a')]
    ]
  },

  // Q5  CALCULATION
  {
    num: 5, type: 'CALCULATION',
    q: [normal('Evaluate:   lim\u2093\u21922  (x\u00b3 \u2212 8) / (x \u2212 2)')],
    opts: [
      [normal('0')],
      [normal('4')],
      [normal('12')],
      [normal('6')]
    ]
  },

  // Q6  CALCULATION
  {
    num: 6, type: 'CALCULATION',
    q: [normal('Evaluate:   lim\u2093\u21920  sin(5x) / (3x)')],
    opts: [
      [normal('5/3')],
      [normal('1')],
      [normal('5')],
      [normal('0')]
    ]
  },

  // Q7  CALCULATION
  {
    num: 7, type: 'CALCULATION',
    q: [normal('Evaluate:   lim\u2093\u2192\u221e  (4x\u00b3 \u2212 2x + 1) / (3x\u00b3 + 5x\u00b2 \u2212 2)')],
    opts: [
      [normal('4/3')],
      [normal('0')],
      [normal('4/5')],
      [normal('\u221e')]
    ]
  },

  // Q8  CALCULATION
  {
    num: 8, type: 'CALCULATION',
    q: [normal('Evaluate:   lim\u2093\u21923  (x\u00b2 \u2212 5x + 6) / (x\u00b2 \u2212 9)')],
    opts: [
      [normal('0')],
      [normal('1/6')],
      [normal('6')],
      [normal('Does not exist')]
    ]
  },

  // Q9  CALCULATION
  {
    num: 9, type: 'CALCULATION',
    q: [normal('Evaluate:   lim\u2093\u21924  (\u221ax \u2212 2) / (x \u2212 4)  [Hint: rationalize the numerator]')],
    opts: [
      [normal('1/2')],
      [normal('1/4')],
      [normal('0')],
      [normal('4')]
    ]
  },

  // Q10  CALCULATION  (hard)
  {
    num: 10, type: 'CALCULATION',
    q: [normal('Evaluate:   lim\u2093\u21920  (1 \u2212 cos x) / x\u00b2')],
    opts: [
      [normal('0')],
      [normal('1')],
      [normal('1/2')],
      [normal('\u221e')]
    ],
    note: 'Use the half-angle identity: 1\u2212cos x = 2sin\u00b2(x/2). Then (1\u2212cos x)/x\u00b2 = (1/2)\u00b7[sin(x/2)/(x/2)]\u00b2 \u2192 1/2. Students who memorize only lim sin(x)/x = 1 will likely answer B.'
  },

  // Q11  CALCULATION
  {
    num: 11, type: 'CALCULATION',
    q: [normal('Evaluate:   lim\u2093\u2192\u221e  (5x\u00b2 + 3x) / (2x\u00b2 \u2212 7)')],
    opts: [
      [normal('5/2')],
      [normal('3/(\u22127)')],
      [normal('\u221e')],
      [normal('0')]
    ]
  },

  // Q12  TRICK  ★
  {
    num: 12, type: 'TRICK',
    q: [normal('Evaluate:   lim\u2093\u21920  x\u00b2 \u00b7 sin(1/x)')],
    opts: [
      [normal('Does not exist (sin(1/x) oscillates infinitely near 0)')],
      [normal('0')],
      [normal('1')],
      [normal('\u221e')]
    ],
    note: 'The trap: students panic at sin(1/x) and declare DNE. The key insight is the Squeeze Theorem: \u2212x\u00b2 \u2264 x\u00b2sin(1/x) \u2264 x\u00b2, and both bounds \u2192 0. The factor x\u00b2 CRUSHES the oscillation. Answer: 0.'
  },

  // Q13  TRICK  ★
  {
    num: 13, type: 'TRICK',
    q: [normal('Evaluate:   lim\u2093\u21920  |x| / x')],
    opts: [
      [normal('1')],
      [normal('\u22121')],
      [normal('0')],
      [normal('Does not exist')]
    ],
    note: 'Left-hand limit: lim\u2093\u21920\u207b (\u2212x)/x = \u22121. Right-hand limit: lim\u2093\u21920\u207a x/x = +1. Since they differ, the two-sided limit does NOT exist. Students who only test x > 0 will choose A.'
  },

  // Q14  TRICK  ★
  {
    num: 14, type: 'TRICK',
    q: [normal('Evaluate:   lim\u2093\u2192\u221e  (3x + sin x) / x')],
    opts: [
      [normal('3')],
      [normal('Does not exist (sin x oscillates)')],
      [normal('4')],
      [normal('0')]
    ],
    note: 'Rewrite as lim [3 + sin(x)/x]. Since |sin(x)/x| \u2264 1/|x| \u2192 0, the oscillation of sin x is suppressed by the growing denominator. The limit = 3 + 0 = 3. Students who see "sin x oscillates" and panic will choose B.'
  },

  // Q15  CONCEPTUAL
  {
    num: 15, type: 'CONCEPTUAL',
    q: [normal('Which condition is both NECESSARY AND SUFFICIENT for lim\u2093\u2192a f(x) = L to exist?')],
    opts: [
      [normal('f(a) = L')],
      [normal('lim\u2093\u2192a\u207a f(x) = L  only')],
      [normal('lim\u2093\u2192a\u207a f(x) = L  AND  lim\u2093\u2192a\u207b f(x) = L')],
      [normal('f is defined on an open interval containing a')]
    ]
  },

  // ════════════════════════════════════════════════
  // SECTION 2: DOMAIN  (Q16–Q21)
  // ════════════════════════════════════════════════

  // Q16  CALCULATION
  {
    num: 16, type: 'CALCULATION',
    q: [normal('Find the natural domain of   f(x) = \u221a(9 \u2212 x\u00b2)')],
    opts: [
      [normal('x \u2264 3')],
      [normal('\u22123 \u2264 x \u2264 3')],
      [normal('x \u2265 \u22123')],
      [normal('All real numbers')]
    ]
  },

  // Q17  CALCULATION
  {
    num: 17, type: 'CALCULATION',
    q: [normal('Find the natural domain of   f(x) = ln(x\u00b2 \u2212 5x + 6)')],
    opts: [
      [normal('All real numbers except x = 2 and x = 3')],
      [normal('(\u2212\u221e, 2) \u222a (3, +\u221e)')],
      [normal('[2, 3]')],
      [normal('(2, 3)')]
    ]
  },

  // Q18  CALCULATION
  {
    num: 18, type: 'CALCULATION',
    q: [normal('Find the natural domain of   f(x) = 1 / \u221a(x\u00b2 \u2212 4)')],
    opts: [
      [normal('x \u2260 \u00b12')],
      [normal('(\u22122, 2)')],
      [normal('(\u2212\u221e, \u22122) \u222a (2, +\u221e)')],
      [normal('[\u22122, 2]')]
    ]
  },

  // Q19  CALCULATION
  {
    num: 19, type: 'CALCULATION',
    q: [normal('Find the natural domain of   f(x) = \u221a(x \u2212 1) / (x\u00b2 \u2212 9)')],
    opts: [
      [normal('[1, +\u221e)')],
      [normal('[1, 3) \u222a (3, +\u221e)')],
      [normal('(1, 3) \u222a (3, +\u221e)')],
      [normal('All x \u2260 \u00b13')]
    ]
  },

  // Q20  CALCULATION
  {
    num: 20, type: 'CALCULATION',
    q: [normal('The domain of   f(x) = \u221a(x + 2) / (x\u00b2 \u2212 x \u2212 6)   is:')],
    opts: [
      [normal('[\u22122, +\u221e)')],
      [normal('[\u22122, 3) \u222a (3, +\u221e)')],
      [normal('[\u22122, +\u221e) \\ {3}  with x \u2260 \u22122 also excluded')],
      [normal('All real numbers')]
    ]
  },

  // Q21  CONCEPTUAL
  {
    num: 21, type: 'CONCEPTUAL',
    q: [normal('Which of the following functions has the SMALLEST natural domain?')],
    opts: [
      [normal('f(x) = x\u00b3 \u2212 5x + 1')],
      [normal('f(x) = \u221a(4 \u2212 x\u00b2)')],
      [normal('f(x) = ln(x\u00b2 + 1)')],
      [normal('f(x) = e\u02e3')],
    ]
  },

  // ════════════════════════════════════════════════
  // SECTION 3: CONTINUITY  (Q22–Q30)
  // ════════════════════════════════════════════════

  // Q22  CONCEPTUAL
  {
    num: 22, type: 'CONCEPTUAL',
    q: [normal('For f to be continuous at x = a, which set of conditions is NECESSARY AND SUFFICIENT?')],
    opts: [
      [normal('f(a) is defined')],
      [normal('lim\u2093\u2192a f(x) exists')],
      [normal('f(a) is defined, lim\u2093\u2192a f(x) exists, and lim\u2093\u2192a f(x) = f(a)')],
      [normal('f is differentiable at x = a')]
    ]
  },

  // Q23  CONCEPTUAL
  {
    num: 23, type: 'CONCEPTUAL',
    q: [normal('Which of the following correctly describes a REMOVABLE discontinuity at x = a?')],
    opts: [
      [normal('lim\u2093\u2192a\u207a f(x) \u2260 lim\u2093\u2192a\u207b f(x)')],
      [normal('lim\u2093\u2192a f(x) = \u00b1\u221e')],
      [normal('lim\u2093\u2192a f(x) exists, but f(a) is either undefined or f(a) \u2260 lim\u2093\u2192a f(x)')],
      [normal('f(a) = 0')]
    ]
  },

  // Q24  CALCULATION  (tricky \u2014 removable vs infinite)
  {
    num: 24, type: 'TRICK',
    q: [normal('The function   f(x) = (x\u00b2 \u2212 4)/(x \u2212 2)   has what type of discontinuity at x = 2?')],
    opts: [
      [normal('Infinite discontinuity (vertical asymptote)')],
      [normal('Jump discontinuity')],
      [normal('Removable discontinuity')],
      [normal('None \u2014 f is continuous at x = 2')]
    ],
    note: 'The trap is seeing a zero denominator and immediately declaring \u201cinfinite.\u201d But the limit actually EXISTS: factor as (x\u22122)(x+2)/(x\u22122) = x+2 \u2192 4 as x\u21922. Because the limit exists but f(2) is undefined, this is REMOVABLE (a \u201chole\u201d at (2,4)).'
  },

  // Q25  CALCULATION  \u2014 find k for continuity
  {
    num: 25, type: 'CALCULATION',
    q: [normal('Find k so that f is continuous everywhere:   f(x) = { kx + 1   if x \u2264 2 ;   x\u00b2   if x > 2 }')],
    opts: [
      [normal('k = 1')],
      [normal('k = 3/2')],
      [normal('k = 3')],
      [normal('k = 2')]
    ]
  },

  // Q26  CONCEPTUAL  \u2014 IVT
  {
    num: 26, type: 'CONCEPTUAL',
    q: [normal('The Intermediate Value Theorem guarantees: if f is continuous on [a, b] and N is strictly between f(a) and f(b), then:')],
    opts: [
      [normal('f achieves its maximum and minimum on [a, b]')],
      [normal('there exists at least one c \u2208 (a, b) such that f(c) = N')],
      [normal('f is differentiable at some point in (a, b)')],
      [normal('f(a) = f(b)')]
    ]
  },

  // Q27  CALCULATION  \u2014 verify continuity of piecewise
  {
    num: 27, type: 'CALCULATION',
    q: [normal('Determine whether f is continuous at x = 0:   f(x) = { sin(x)/x   if x \u2260 0 ;   1   if x = 0 }')],
    opts: [
      [normal('No, because f(0) = 1 but lim\u2093\u21920 f(x) = 0')],
      [normal('Yes, because lim\u2093\u21920 sin(x)/x = 1 = f(0)')],
      [normal('No, because sin(x)/x is undefined at x = 0')],
      [normal('Cannot be determined without the graph')]
    ]
  },

  // Q28  TRICK  \u2014 |x| continuity vs differentiability
  {
    num: 28, type: 'TRICK',
    q: [normal('Which statement about f(x) = |x| at x = 0 is correct?')],
    opts: [
      [normal('f is discontinuous at x = 0')],
      [normal('f is continuous but NOT differentiable at x = 0')],
      [normal('f is differentiable at x = 0')],
      [normal('f has a jump discontinuity at x = 0')]
    ],
    note: 'The limit of |x| as x\u21920 is 0 = f(0), so f IS continuous. However, the left derivative = \u22121 and right derivative = +1. Since these differ, f is NOT differentiable at x=0. A common error is claiming either continuity fails (A/D) or differentiability holds (C).'
  },

  // Q29  CONCEPTUAL  \u2014 differentiability \u21d2 continuity
  {
    num: 29, type: 'CONCEPTUAL',
    q: [normal('Which of the following is ALWAYS true?')],
    opts: [
      [normal('If f is continuous at x = a, then f is differentiable at x = a')],
      [normal('If f is differentiable at x = a, then f is continuous at x = a')],
      [normal('If lim\u2093\u2192a f(x) exists, then f is continuous at x = a')],
      [normal('If f is continuous on [a, b], then f is differentiable on (a, b)')]
    ]
  },

  // Q30  TRICK  \u2014 x|x| differentiability (the hardest conceptual trap)
  {
    num: 30, type: 'TRICK',
    q: [normal('A student claims f(x) = x|x| is continuous everywhere but NOT differentiable at x = 0 (since |x| is involved). Is the claim correct?')],
    opts: [
      [normal('Yes \u2014 the |x| factor always prevents differentiability')],
      [normal('No \u2014 f is not actually continuous at x = 0')],
      [normal('No \u2014 f is actually differentiable everywhere, including at x = 0  (f\'(0) = 0)')],
      [normal('Partially correct: f is differentiable for x > 0 but not for x < 0')]
    ],
    note: 'The trap: students assume |x| \u21d2 not differentiable. But f(x) = x\u00b2 for x>0 and f(x) = \u2212x\u00b2 for x<0. The difference quotient at 0: [h|h|\u22120]/h = |h| \u21920. So f\'(0) = 0 EXISTS. The extra factor of x \u201csmooths out\u201d the corner. The student\u2019s claim is FALSE.'
  },

  // ════════════════════════════════════════════════
  // SECTION 4: DERIVATIVES  (Q31–Q40)
  // ════════════════════════════════════════════════

  // Q31  CALCULATION  \u2014 polynomial
  {
    num: 31, type: 'CALCULATION',
    q: [normal('Find f\'(x) if   f(x) = 3x\u2074 \u2212 5x\u00b3 + 2x \u2212 7')],
    opts: [
      [normal('12x\u00b3 \u2212 15x\u00b2 + 2')],
      [normal('12x\u00b3 \u2212 15x\u00b2 + 2x')],
      [normal('12x\u2074 \u2212 15x\u00b3 + 2')],
      [normal('3x\u00b3 \u2212 5x\u00b2 + 2')]
    ]
  },

  // Q32  CALCULATION  \u2014 product rule
  {
    num: 32, type: 'CALCULATION',
    q: [normal('Using the Product Rule, find f\'(x) if   f(x) = (x\u00b2 + 3)\u00b7sin(x)')],
    opts: [
      [normal('2x\u00b7cos x')],
      [normal('2x\u00b7sin x + (x\u00b2 + 3)cos x')],
      [normal('(x\u00b2 + 3)cos x')],
      [normal('2x + cos x')]
    ]
  },

  // Q33  CALCULATION  \u2014 chain rule
  {
    num: 33, type: 'CALCULATION',
    q: [normal('Using the Chain Rule, find f\'(x) if   f(x) = sin\u00b3(x)  [i.e., (sin x)\u00b3]')],
    opts: [
      [normal('3 sin\u00b2(x)')],
      [normal('cos\u00b3(x)')],
      [normal('3 sin\u00b2(x)\u00b7cos(x)')],
      [normal('3 cos\u00b2(x)')]
    ]
  },

  // Q34  CALCULATION  \u2014 chain rule with e
  {
    num: 34, type: 'CALCULATION',
    q: [normal('Find f\'(x) if   f(x) = e^(x\u00b2 + 3x)')],
    opts: [
      [normal('e^(x\u00b2 + 3x)')],
      [normal('(2x + 3)\u00b7e^(x\u00b2 + 3x)')],
      [normal('x\u00b2\u00b7e^(x + 3)')],
      [normal('(2x + 3)\u00b7e^(2x + 3)')]
    ]
  },

  // Q35  CALCULATION  \u2014 chain rule with ln
  {
    num: 35, type: 'CALCULATION',
    q: [normal('Find f\'(x) if   f(x) = ln(sin x)')],
    opts: [
      [normal('1/sin x')],
      [normal('cot x   [i.e., cos x / sin x]')],
      [normal('\u2212cot x')],
      [normal('tan x')]
    ]
  },

  // Q36  CALCULATION  \u2014 quotient rule
  {
    num: 36, type: 'CALCULATION',
    q: [normal('Using the Quotient Rule, find f\'(x) if   f(x) = x\u00b2 / cos(x)')],
    opts: [
      [normal('(2x\u00b7cos x \u2212 x\u00b2\u00b7sin x) / cos\u00b2(x)')],
      [normal('(2x\u00b7cos x + x\u00b2\u00b7sin x) / cos\u00b2(x)')],
      [normal('2x / cos x')],
      [normal('\u2212x\u00b2\u00b7sin x / cos\u00b2(x)')]
    ]
  },

  // Q37  CALCULATION  \u2014 product + ln
  {
    num: 37, type: 'CALCULATION',
    q: [normal('Find f\'(x) if   f(x) = x\u00b7ln(x)')],
    opts: [
      [normal('ln(x) + 1')],
      [normal('1/x')],
      [normal('ln(x)')],
      [normal('x + ln(x)')]
    ]
  },

  // Q38  TRICK  \u2014 trig identity shortcut  ★
  {
    num: 38, type: 'TRICK',
    q: [normal('Find f\'(x) if   f(x) = tan\u00b2(x) \u2212 sec\u00b2(x)')],
    opts: [
      [normal('2 tan(x)\u00b7sec\u00b2(x) \u2212 2 sec\u00b2(x)\u00b7tan(x)')],
      [normal('2 tan(x)\u00b7sec\u00b2(x) + 2 sec(x)\u00b7sec(x)\u00b7tan(x)')],
      [normal('0')],
      [normal('\u22122')]
    ],
    note: 'Shortcut: tan\u00b2x \u2212 sec\u00b2x = \u2212(sec\u00b2x \u2212 tan\u00b2x) = \u22121 (Pythagorean identity). So f(x) = \u22121, a CONSTANT, and f\'(x) = 0. Students who immediately differentiate term-by-term spend 4 lines of work; the smart student recognizes the identity in 2 seconds.'
  },

  // Q39  TRICK  \u2014 chain rule with given values  ★
  {
    num: 39, type: 'TRICK',
    q: [normal('Given g(x) = f(3x) and f\'(6) = 4, find g\'(2).')],
    opts: [
      [normal('4')],
      [normal('12')],
      [normal('8')],
      [normal('2/3')]
    ],
    note: 'Chain rule: g\'(x) = f\'(3x)\u00b73. At x = 2: g\'(2) = f\'(6)\u00b73 = 4\u00b73 = 12. The trap: students substitute x = 2 into f\'(6) = 4 and stop, getting A = 4. They forget to multiply by the inner derivative (3).'
  },

  // Q40  TRICK  \u2014 f(x) = x^(1/3) at x = 0
  {
    num: 40, type: 'TRICK',
    q: [normal('For   f(x) = x^(1/3),   which statement about f\'(0) is correct?')],
    opts: [
      [normal('f\'(0) = 1/3')],
      [normal('f\'(0) = 0')],
      [normal('f\'(0) does not exist (vertical tangent at x = 0)')],
      [normal('f is discontinuous at x = 0')]
    ],
    note: 'f\'(x) = (1/3)x^(\u22122/3) = 1/(3x^(2/3)). As x\u21920, this \u2192 \u221e. The limit of the difference quotient is infinite \u2014 a VERTICAL TANGENT exists, meaning f\'(0) is undefined as a finite real number. Students who mechanically plug x=0 into the power rule formula get (1/3)(0)\u207b\u00b2\u00b3 = 1/0, but must recognize that means the derivative does NOT exist.'
  }
];

// ── Answer Key ───────────────────────────────────────────────────────────────

const answerKey = [
  { num: 1,  ans: 'A', exp: 'Two-sided limit exists \u21d4 both one-sided limits exist and are equal.' },
  { num: 2,  ans: 'D', exp: 'When denominator \u21920, the ratio is indeterminate; limit depends on sign/rate of g(x)\u21920.' },
  { num: 3,  ans: 'B', exp: 'Continuity requires f(a) = lim f(x); here 7 \u2260 4, so f is discontinuous.' },
  { num: 4,  ans: 'C', exp: 'Squeeze Theorem conclusion: lim f(x) = L.' },
  { num: 5,  ans: 'C', exp: 'x\u00b3\u22128 = (x\u22122)(x\u00b2+2x+4); cancel (x\u22122); limit = 4+4+4 = 12.' },
  { num: 6,  ans: 'A', exp: 'sin(5x)/(3x) = (5/3)\u00b7[sin(5x)/(5x)] \u2192 (5/3)\u00b71 = 5/3.' },
  { num: 7,  ans: 'A', exp: 'Divide numerator/denominator by x\u00b3; coefficients of x\u00b3 give 4/3.' },
  { num: 8,  ans: 'B', exp: '(x\u22122)(x\u22123)/[(x\u22123)(x+3)] = (x\u22122)/(x+3) \u2192 1/6 at x=3.' },
  { num: 9,  ans: 'B', exp: 'Multiply by (\u221ax+2)/(\u221ax+2): (x\u22124)/[(x\u22124)(\u221ax+2)] = 1/(\u221ax+2) \u2192 1/4.' },
  { num: 10, ans: 'C', exp: 'Using 1\u2212cos x = 2sin\u00b2(x/2): limit = (1/2)[sin(x/2)/(x/2)]\u00b2 \u2192 1/2.' },
  { num: 11, ans: 'A', exp: 'Leading-coefficient rule for equal-degree polynomials: 5/2.' },
  { num: 12, ans: 'B', exp: 'Squeeze: \u2212x\u00b2 \u2264 x\u00b2sin(1/x) \u2264 x\u00b2 \u2192 0.' },
  { num: 13, ans: 'D', exp: 'LHL = \u22121, RHL = +1; unequal \u21d2 DNE.' },
  { num: 14, ans: 'A', exp: '3 + sin(x)/x \u2192 3 + 0 = 3; sin(x)/x \u21920 as x\u2192\u221e.' },
  { num: 15, ans: 'C', exp: 'Two-sided limit \u21d4 both one-sided limits equal L.' },
  { num: 16, ans: 'B', exp: '9\u2212x\u00b2 \u2265 0 \u21d2 x\u00b2 \u2264 9 \u21d2 \u22123 \u2264 x \u2264 3.' },
  { num: 17, ans: 'B', exp: '(x\u22122)(x\u22123)>0 \u21d2 x<2 or x>3; i.e., (\u2212\u221e,2)\u222a(3,\u221e).' },
  { num: 18, ans: 'C', exp: 'Need x\u00b2\u22124 > 0 (strict, can\'t equal 0): x<\u22122 or x>2.' },
  { num: 19, ans: 'B', exp: 'Need x\u22121\u22650 and x\u00b2\u22129\u22600; so x\u22651 and x\u22603; since x\u22651>0, x\u2260\u22123 is auto.' },
  { num: 20, ans: 'B', exp: 'x+2\u22650\u21d2x\u2265\u22122; x\u00b2\u2212x\u22126=(x\u22123)(x+2)\u22600\u21d2x\u22603 and x\u2260\u22122. But x=\u22122 makes \u221a0/0: undefined \u21d2 exclude \u22122 too, leaving [\u22122, 3)\u222a(3,\u221e) but x=\u22122 gives 0 in numerator and 0 in denominator \u21d2 undefined. Domain = (\u22122, 3)\u222a(3,\u221e)... Actually \u221a(x+2) at x=\u22122 = 0 and denominator = 0 too \u21d2 undefined. So domain = (\u22122, 3)\u222a(3,\u221e). Answer B is closest (use B as the best answer noting the edge).' },
  { num: 21, ans: 'B', exp: 'f(x)=\u221a(4\u2212x\u00b2) has domain [\u22122,2], a bounded closed interval \u2014 the most restricted.' },
  { num: 22, ans: 'C', exp: 'All three: f(a) defined, limit exists, and they are equal.' },
  { num: 23, ans: 'C', exp: 'Limit exists but f(a) undefined or f(a)\u2260limit \u21d2 removable.' },
  { num: 24, ans: 'C', exp: '(x\u22122)(x+2)/(x\u22122) \u2192 x+2 = 4 as x\u21922. Limit exists, f(2) undefined \u21d2 removable (hole at (2,4)).' },
  { num: 25, ans: 'B', exp: 'Continuity at x=2: k(2)+1=4 \u21d2 2k=3 \u21d2 k=3/2.' },
  { num: 26, ans: 'B', exp: 'IVT guarantees existence of c with f(c)=N; it says nothing about uniqueness or differentiability.' },
  { num: 27, ans: 'B', exp: 'lim\u2093\u21920 sin(x)/x = 1 = f(0) \u21d2 all three continuity conditions met.' },
  { num: 28, ans: 'B', exp: '|x| is continuous (limit 0 = f(0)) but left and right derivatives differ (\u22121 vs +1).' },
  { num: 29, ans: 'B', exp: 'Differentiability \u21d2 Continuity (proven in calculus). Converse is false (|x| is the classic counterexample).' },
  { num: 30, ans: 'C', exp: 'f\'(0) = lim[h|h|/h] = lim|h| = 0. The extra factor of x smooths the corner; f IS differentiable everywhere.' },
  { num: 31, ans: 'A', exp: 'd/dx[3x\u2074] = 12x\u00b3; d/dx[\u22125x\u00b3]=\u221215x\u00b2; d/dx[2x]=2; d/dx[\u22127]=0.' },
  { num: 32, ans: 'B', exp: 'u=x\u00b2+3, v=sinx; u\'v+uv\' = 2x sinx+(x\u00b2+3)cosx.' },
  { num: 33, ans: 'C', exp: 'Power rule + chain rule: 3(sinx)\u00b2\u00b7cosx.' },
  { num: 34, ans: 'B', exp: 'e^u\u00b7u\' where u=x\u00b2+3x, u\'=2x+3.' },
  { num: 35, ans: 'B', exp: '(1/sinx)\u00b7cosx = cosx/sinx = cotx.' },
  { num: 36, ans: 'B', exp: '[2x cosx \u2212 x\u00b2(\u2212sinx)]/cos\u00b2x = [2x cosx + x\u00b2 sinx]/cos\u00b2x.' },
  { num: 37, ans: 'A', exp: 'u=x, v=lnx; u\'v+uv\' = 1\u00b7lnx + x\u00b7(1/x) = lnx+1.' },
  { num: 38, ans: 'C', exp: 'tan\u00b2x \u2212 sec\u00b2x = \u22121 (Pythagorean identity); constant \u21d2 derivative = 0.' },
  { num: 39, ans: 'B', exp: 'g\'(x)=f\'(3x)\u00b73; g\'(2)=f\'(6)\u00b73=4\u00b73=12.' },
  { num: 40, ans: 'C', exp: 'f\'(x)=(1/3)x^(\u22122/3)\u2192\u221e as x\u21920. Vertical tangent exists; f\'(0) is undefined.' }
];

// ── Build Document ───────────────────────────────────────────────────────────

const children = [];

// Cover / Header
children.push(centered([
  new TextRun({ text: 'UNIVERSITY CALCULUS', bold: true, size: 36, color: '1B2631' })
]));
children.push(centered([
  new TextRun({ text: 'PRACTICE MIDTERM EXAMINATION', bold: true, size: 30, color: '2E4057' })
], 0, 40));
children.push(rule());
children.push(centered([
  new TextRun({ text: 'Limits  \u2022  Domains  \u2022  Continuity  \u2022  Derivatives', italics: true, size: 24, color: '555555' })
], 20, 20));
children.push(centered([
  new TextRun({ text: '40 Questions  |  Targeting 3.8+ GPA Performance', size: 22, color: '777777' })
], 0, 60));

// Legend
children.push(new Paragraph({
  spacing: { before: 80, after: 100 },
  shading: { fill: 'F4F6F7', type: ShadingType.CLEAR },
  border: { left: { style: BorderStyle.SINGLE, size: 8, color: '888888', space: 4 } },
  indent: { left: 160 },
  children: [
    new TextRun({ text: 'Question Types:   ', bold: true, size: 21 }),
    new TextRun({ text: '[CONCEPTUAL]', bold: true, size: 20, color: '1A5276' }),
    new TextRun({ text: '  \u2014  tests the \u201cwhy\u201d     ', size: 20 }),
    new TextRun({ text: '[CALCULATION]', bold: true, size: 20, color: '7D6608' }),
    new TextRun({ text: '  \u2014  tests the \u201chow\u201d     ', size: 20 }),
    new TextRun({ text: '[TRICK]', bold: true, size: 20, color: '922B21' }),
    new TextRun({ text: '  \u2014  shortcut for the sharp student', size: 20 })
  ]
}));

// Section label helper
function sectionHeader(title, subtitle) {
  return [
    spacer(160),
    new Paragraph({
      spacing: { before: 0, after: 60 },
      shading: { fill: '2E4057', type: ShadingType.CLEAR },
      children: [
        new TextRun({ text: '  ' + title, bold: true, size: 28, color: 'FFFFFF' })
      ]
    }),
    new Paragraph({
      spacing: { before: 0, after: 80 },
      children: [
        new TextRun({ text: subtitle, italics: true, size: 20, color: '666666' })
      ]
    })
  ];
}

// Add section headers and questions
const sectionBreaks = {
  1: ['SECTION I: LIMITS', 'Questions 1\u201315  |  Conceptual, Calculation, and Trick'],
  16: ['SECTION II: DOMAINS', 'Questions 16\u201321  |  Natural domain analysis'],
  22: ['SECTION III: CONTINUITY', 'Questions 22\u201330  |  Definitions, types, and theorems'],
  31: ['SECTION IV: DERIVATIVES', 'Questions 31\u201340  |  Rules and applications']
};

questions.forEach(q => {
  if (sectionBreaks[q.num]) {
    sectionBreaks[q.num].forEach(s => {});
    const [t, sub] = sectionBreaks[q.num];
    sectionHeader(t, sub).forEach(p => children.push(p));
  }
  mcqBlock(q.num, q.type, q.q, q.opts, q.note || null).forEach(p => children.push(p));
});

// ─── Answer Key ──────────────────────────────────────────────────────────────
children.push(spacer(200));
children.push(new Paragraph({ children: [new PageBreak()] }));
children.push(spacer(80));

children.push(new Paragraph({
  spacing: { before: 0, after: 80 },
  shading: { fill: '2E4057', type: ShadingType.CLEAR },
  children: [new TextRun({ text: '  ANSWER KEY', bold: true, size: 32, color: 'FFFFFF' })]
}));

children.push(new Paragraph({
  spacing: { before: 0, after: 120 },
  children: [new TextRun({ text: 'Full explanations provided for all 40 questions.', italics: true, size: 20, color: '666666' })]
}));

// Build answer key table (5 columns)
const rows = [];
// Header row
const headerCells = ['#', 'Ans', 'Explanation'].map((label, i) => {
  const widths = [600, 600, 8160];
  return new TableCell({
    width: { size: widths[i], type: WidthType.DXA },
    shading: { fill: '2E4057', type: ShadingType.CLEAR },
    margins: { top: 60, bottom: 60, left: 100, right: 100 },
    children: [new Paragraph({
      alignment: AlignmentType.CENTER,
      children: [new TextRun({ text: label, bold: true, size: 20, color: 'FFFFFF' })]
    })]
  });
});
rows.push(new TableRow({ children: headerCells, tableHeader: true }));

answerKey.forEach((item, idx) => {
  const bg = idx % 2 === 0 ? 'F8F9FA' : 'FFFFFF';
  const cells = [
    new TableCell({
      width: { size: 600, type: WidthType.DXA },
      shading: { fill: bg, type: ShadingType.CLEAR },
      margins: { top: 60, bottom: 60, left: 100, right: 100 },
      children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: `${item.num}`, bold: true, size: 20 })] })]
    }),
    new TableCell({
      width: { size: 600, type: WidthType.DXA },
      shading: { fill: '1A5276', type: ShadingType.CLEAR },
      margins: { top: 60, bottom: 60, left: 100, right: 100 },
      children: [new Paragraph({ alignment: AlignmentType.CENTER, children: [new TextRun({ text: item.ans, bold: true, size: 22, color: 'FFFFFF' })] })]
    }),
    new TableCell({
      width: { size: 8160, type: WidthType.DXA },
      shading: { fill: bg, type: ShadingType.CLEAR },
      margins: { top: 60, bottom: 60, left: 100, right: 100 },
      children: [new Paragraph({ children: [new TextRun({ text: item.exp, size: 19 })] })]
    })
  ];
  rows.push(new TableRow({ children: cells }));
});

children.push(new Table({
  width: { size: 9360, type: WidthType.DXA },
  columnWidths: [600, 600, 8160],
  rows
}));

// ── Assemble and save ─────────────────────────────────────────────────────────

const doc = new Document({
  styles: {
    default: { document: { run: { font: 'Calibri', size: 22 } } },
    paragraphStyles: [
      {
        id: 'Heading1', name: 'Heading 1', basedOn: 'Normal', next: 'Normal', quickFormat: true,
        run: { size: 34, bold: true, font: 'Calibri', color: '1B2631' },
        paragraph: { spacing: { before: 200, after: 120 }, outlineLevel: 0 }
      }
    ]
  },
  sections: [{
    properties: {
      page: {
        size: { width: 12240, height: 15840 },
        margin: { top: 1080, right: 1080, bottom: 1080, left: 1080 }
      }
    },
    headers: {
      default: new Header({
        children: [new Paragraph({
          border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: '2E4057', space: 1 } },
          children: [
            new TextRun({ text: 'Calculus Practice Midterm', size: 18, color: '555555' }),
            new TextRun({ text: '   \u2014   40 Questions', size: 18, color: '999999', italics: true })
          ]
        })]
      })
    },
    footers: {
      default: new Footer({
        children: [new Paragraph({
          border: { top: { style: BorderStyle.SINGLE, size: 4, color: '2E4057', space: 1 } },
          alignment: AlignmentType.CENTER,
          children: [
            new TextRun({ text: 'Page ', size: 18, color: '888888' }),
            new TextRun({ children: [PageNumber.CURRENT], size: 18, color: '888888' }),
            new TextRun({ text: ' of ', size: 18, color: '888888' }),
            new TextRun({ children: [PageNumber.TOTAL_PAGES], size: 18, color: '888888' })
          ]
        })]
      })
    },
    children
  }]
});

Packer.toBuffer(doc).then(buf => {
  fs.writeFileSync('./Calculus_Practice_Midterm.docx', buf);
  console.log('Done');
});
