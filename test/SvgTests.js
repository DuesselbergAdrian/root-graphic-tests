const { TestMacros } = require('../Test_JSON'); // Adjust the path and method based on your actual file structure

describe('TestGraphicJSON', () => {
    test('AnalyzeFunction', () => {
        const macroPath = 'analyze';
        expect(TestMacros(macroPath)).toBeTruthy();
    });

    test('ArchiFunction', () => {
        const macroPath = 'archi';
        expect(TestMacros(macroPath)).toBeTruthy();
    });

    test('ArrowsFunction', () => {
        const macroPath = 'arrows';
        expect(TestMacros(macroPath)).toBeTruthy();
    });
});