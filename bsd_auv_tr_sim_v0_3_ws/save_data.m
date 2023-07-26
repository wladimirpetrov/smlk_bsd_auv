dlgTitle    = 'User Question';
dlgQuestion = 'Would you like to save this workspace?';
choice = questdlg(dlgQuestion,dlgTitle,'Yes','No', 'Yes');

if choice == 'Yes' %#ok<BDSCA> 
    prompt = "What would you like to name this file?";
    dlgTitle2 = 'User Question';
    userInput = inputdlg(prompt,dlgTitle);
    filename = char(userInput);
    save(filename)
end
