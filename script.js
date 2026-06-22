let display = document.getElementById('display');
let currentInput = '';
let previousInput = '';
let operator = null;

function appendNumber(num) {
    if (num === '.' && currentInput.includes('.')) return;
    currentInput += num;
    updateDisplay();
}

function appendOperator(op) {
    if (currentInput === '') return;
    
    if (previousInput !== '') {
        calculate();
    }
    
    operator = op;
    previousInput = currentInput;
    currentInput = '';
}

function calculate() {
    if (previousInput === '' || currentInput === '' || operator === null) return;
    
    let result;
    const prev = parseFloat(previousInput);
    const current = parseFloat(currentInput);
    
    switch (operator) {
        case '+':
            result = prev + current;
            break;
        case '-':
            result = prev - current;
            break;
        case '*':
            result = prev * current;
            break;
        case '/':
            result = current !== 0 ? prev / current : 'Error';
            break;
        default:
            return;
    }
    
    currentInput = result.toString();
    previousInput = '';
    operator = null;
    updateDisplay();
}

function clearDisplay() {
    currentInput = '';
    previousInput = '';
    operator = null;
    updateDisplay();
}

function deleteLast() {
    currentInput = currentInput.slice(0, -1);
    updateDisplay();
}

function updateDisplay() {
    display.value = currentInput || '0';
}

// Allow keyboard input
document.addEventListener('keydown', (e) => {
    if (e.key >= '0' && e.key <= '9') appendNumber(e.key);
    if (e.key === '.') appendNumber('.');
    if (e.key === '+' || e.key === '-' || e.key === '*' || e.key === '/') {
        e.preventDefault();
        appendOperator(e.key);
    }
    if (e.key === 'Enter' || e.key === '=') {
        e.preventDefault();
        calculate();
    }
    if (e.key === 'Backspace') {
        e.preventDefault();
        deleteLast();
    }
    if (e.key === 'Escape') {
        clearDisplay();
    }
});
