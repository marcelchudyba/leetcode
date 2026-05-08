import tkinter as tk
from tkinter import ttk, messagebox
import os
import re
from datetime import datetime

# Gets the directory where this script is located
ROOT_DIR = os.path.dirname(os.path.abspath(__file__))

def get_folders():
    folders = []
    try:
        for item in os.listdir(ROOT_DIR):
            path = os.path.join(ROOT_DIR, item)
            if os.path.isdir(path) and not item.startswith('.'):
                folders.append(item)
    except Exception:
        pass
    return sorted(folders)

def clean_topic_name(folder_name):
    clean = re.sub(r'^\d+_', '', folder_name)
    return clean.replace('_', ' ').title()

def add_problem():
    problem_id = id_var.get().strip()
    name = name_var.get().strip()
    link = link_var.get().strip()
    difficulty = difficulty_var.get()
    time_comp = time_var.get().strip()
    space_comp = space_var.get().strip()
    target_folder = folder_var.get().strip()
    code = text_code.get("1.0", tk.END).strip()

    if not problem_id or not name or not target_folder or not code:
        messagebox.showwarning("Missing Fields", "Please fill in ID, Problem Name, Folder, and paste the code!")
        return

    full_folder_path = os.path.join(ROOT_DIR, target_folder)
    if not os.path.exists(full_folder_path):
        os.makedirs(full_folder_path)

    safe_name = name.lower().replace(" ", "_").replace("-", "_")
    file_name = f"{problem_id}_{safe_name}.cpp"
    file_path = os.path.join(full_folder_path, file_name)
    current_date = datetime.now().strftime("%Y-%m-%d")

    cpp_template = f"""// Link: {link}
// Difficulty: {difficulty}
// Time Complexity: {time_comp}
// Space Complexity: {space_comp}
// Date: {current_date}

{code}
"""
    try:
        # 1. Save .cpp file
        with open(file_path, "w", encoding="utf-8") as f:
            f.write(cpp_template)

        # 2. Update README.md (Bulletproof method)
        readme_path = os.path.join(ROOT_DIR, "README.md")
        
        # Check if README exists, if not - create it
        if not os.path.exists(readme_path):
            with open(readme_path, "w", encoding="utf-8") as f:
                f.write("# Algorithms and Data Structures - LeetCode\n\n")
                f.write("| ID | Problem | Difficulty | Topic | Solution |\n")
                f.write("|---|---|---|---|---|\n")

        emojis = {"Easy": "🟢 Easy", "Medium": "🟡 Medium", "Hard": "🔴 Hard"}
        diff_str = emojis.get(difficulty, difficulty)
        clean_topic = clean_topic_name(target_folder)
        relative_path = f"./{target_folder}/{file_name}"
        
        new_row = f"| {problem_id} | {name} | {diff_str} | {clean_topic} | [C++]({relative_path}) |"

        # Read entire content
        with open(readme_path, "r", encoding="utf-8") as f:
            content = f.read()

        # Overwrite file with appended content and guaranteed newlines
        with open(readme_path, "w", encoding="utf-8") as f:
            if content and not content.endswith('\n'):
                f.write(content + '\n' + new_row + '\n')
            else:
                f.write(content + new_row + '\n')

        messagebox.showinfo("Success", f"Problem '{name}' added successfully!")
        
        id_var.set("")
        name_var.set("")
        link_var.set("")
        text_code.delete("1.0", tk.END)
        combo_folder['values'] = get_folders()

    except Exception as e:
        messagebox.showerror("Error", f"An error occurred:\n{str(e)}")

# --- GUI SETUP ---
root = tk.Tk()
root.title("LeetCode Automator")
root.geometry("600x650")
root.configure(padx=20, pady=20)

id_var = tk.StringVar()
name_var = tk.StringVar()
link_var = tk.StringVar()
difficulty_var = tk.StringVar(value="Easy")
time_var = tk.StringVar(value="O(n)")
space_var = tk.StringVar(value="O(n)")
folder_var = tk.StringVar()

frame_top = tk.Frame(root)
frame_top.pack(fill="x", pady=(0, 10))

tk.Label(frame_top, text="ID (e.g. 0001):").pack(side="left")
tk.Entry(frame_top, textvariable=id_var, width=10).pack(side="left", padx=(5, 20))

tk.Label(frame_top, text="Problem (e.g. Two Sum):").pack(side="left")
tk.Entry(frame_top, textvariable=name_var).pack(side="left", padx=(5, 0), expand=True, fill="x")

tk.Label(root, text="Category / Folder:", anchor="w").pack(fill="x")
combo_folder = ttk.Combobox(root, textvariable=folder_var, values=get_folders())
combo_folder.pack(fill="x", pady=(0, 10))

tk.Label(root, text="LeetCode Link:", anchor="w").pack(fill="x")
tk.Entry(root, textvariable=link_var).pack(fill="x", pady=(0, 10))

frame_params = tk.Frame(root)
frame_params.pack(fill="x", pady=10)

tk.Label(frame_params, text="Difficulty:").grid(row=0, column=0, sticky="w", padx=5)
ttk.Combobox(frame_params, textvariable=difficulty_var, values=["Easy", "Medium", "Hard"], width=10).grid(row=1, column=0, padx=5)

tk.Label(frame_params, text="Time Complexity:").grid(row=0, column=1, sticky="w", padx=5)
ttk.Combobox(frame_params, textvariable=time_var, values=["O(1)", "O(log n)", "O(n)", "O(n log n)", "O(n^2)"], width=15).grid(row=1, column=1, padx=5)

tk.Label(frame_params, text="Space Complexity:").grid(row=0, column=2, sticky="w", padx=5)
ttk.Combobox(frame_params, textvariable=space_var, values=["O(1)", "O(log n)", "O(n)", "O(n^2)"], width=15).grid(row=1, column=2, padx=5)

tk.Label(root, text="Paste C++ Code:", anchor="w").pack(fill="x", pady=(15, 0))
text_code = tk.Text(root, height=15)
text_code.pack(fill="both", expand=True, pady=(0, 15))

tk.Button(root, text="ADD TO REPOSITORY", bg="#2094f3", fg="white", font=("Arial", 11, "bold"), command=add_problem).pack(fill="x", ipady=10)

root.mainloop()