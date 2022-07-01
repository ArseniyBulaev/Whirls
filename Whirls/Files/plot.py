from matplotlib import pyplot as plt


def main():


    X = []
    Y = []

    with open("output.txt") as output_file:

        header = output_file.readline()
        splited_header = header.split()

        for i in range(len(splited_header)//2):
            X.append([])
            Y.append([])

        for line in output_file:

            splited_line = line.split()

            for value_index in range(len(splited_line)):
                if value_index % 2 == 0:
                    X[value_index // 2].append(float(splited_line[value_index]))
                else:
                    Y[value_index // 2].append(float(splited_line[value_index]))
            

    for i in range(len(X)):
        plt.plot(X[i], Y[i], label= "Whirl {0}".format(i + 1))
    
    plt.legend()
    plt.savefig("result.png")


if __name__ == "__main__":
    main()