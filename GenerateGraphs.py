import json
import os
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd 

with open('./Json/Results.json', 'r') as file:
    data = json.load(file)

output_folder = 'Graphs'
os.makedirs(output_folder, exist_ok=True)

for test in data:
    df = pd.DataFrame(test["results"])

    sns.set_style("dark")
    sns.set_style(rc = {'axes.facecolor': '#0d1117' })
    plt.figure(figsize=(10, 6))
    ax = plt.gca()

    for i, library in enumerate(df["libraryName"].unique()):
        library_data = df[df["libraryName"] == library]
        for j, result_type in enumerate(library_data["resultType"].unique()):
            result_data = library_data[library_data["resultType"] == result_type]
            color = result_data["color"].iloc[0]
            ax.bar(i + j * 0.2, result_data["resultSpeed"].iloc[0], width=0.2, color=color, label=result_type)

    ax.set_xticks(range(len(df["libraryName"].unique())))
    ax.set_xticklabels(df["libraryName"].unique())
    ax.set_title(f'{test["testName"]} Results', color='white')
    outside_color = "#0d1117"
    ax.set_xlabel('Library Name', color='white')
    ax.set_ylabel('Result Speed MB/s', color='white')

    sns.set_theme(style="whitegrid", rc={"axes.edgecolor": outside_color, "xtick.color": outside_color, "ytick.color": outside_color})
    plt.gcf().set_facecolor(outside_color)

    handles, labels = ax.get_legend_handles_labels() 
    for text in ax.get_xticklabels() + ax.get_yticklabels():
        text.set_color('lightgray')

    legend = ax.legend(title='Result Type', loc='best')

    outside_color = "lightgray"

    output_file_path = os.path.join(output_folder, f'{test["testName"]}_Results.png')
    plt.savefig(output_file_path)

    plt.show()

    print('Graphs saved successfully in the "Graphs" folder.')
