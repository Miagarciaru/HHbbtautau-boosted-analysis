import onnx

# Loading model
# model = onnx.load("GN2_bbtautau_v00_boosted_baseline_fold_0_fold_1.onnx")
model = onnx.load("ML_models/bdt_model_bb_jets.onnx")

for initializer in model.graph.initializer:
    print(f"Tensor name: {initializer.name}, data_type: {initializer.data_type}")


# Validity of the model
onnx.checker.check_model(model)

# Get the model graph
graph = model.graph

# for tensor in model.graph.initializer:
#     print(f"Tensor name: {tensor.name}, data_type: {tensor.data_type}")

# Printing entries, outputs and nodes
print("Entries:")
for entry in graph.input:
    print(entry.name, entry.type)

print("\nOutputs:")
for output in graph.output:
    print(output.name, output.type)

print("\nNodes:")
for node in graph.node:
    print(f"{node.op_type}: {node.name if node.name else '(no name)'}")
    print("  Inputs :", node.input)
    print("  Outputs:", node.output)

# Trained parameters
print("\nWeights (initializers):")
for initializer in graph.initializer:
    print(f"{initializer.name}: {initializer.dims} ({initializer.data_type})")

# Optional: node attributes
for node in graph.node:
    print(f"Node: {node.op_type}")
    for atributte in node.attribute:
        print(f"  Atributte: {atributte.name} = {onnx.helper.get_attribute_value(atributte)}")

