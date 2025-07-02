import onnx
import numpy as np
from onnx import helper, numpy_helper

# Carga el modelo ONNX
model_path = "ML_models/bdt_model_bb_jets.onnx"
model = onnx.load(model_path)

# Tensores que queremos convertir a int32
tensors_a_cambiar = {"classes_ind3", "axis", "shape_tensor", "shape_tensor1"}

tensors_to_change = {"classes", "classes_ind3", "axis", "shape_tensor", "shape_tensor1", "zero_scalar"}

# Filtrar fuera el tensor 'classes' de los inicializadores
new_initializers = []
for tensor in model.graph.initializer:
    if tensor.name in tensors_to_change:
        arr = numpy_helper.to_array(tensor).astype(np.float32)
        new_tensor = numpy_helper.from_array(arr, name=tensor.name)
        new_initializers.append(new_tensor)
        print("Convertido tensor 'classes' a float32")
    else:
        new_initializers.append(tensor)

# Reemplazar todos los inicializadores con la nueva lista
model.graph.ClearField("initializer")
model.graph.initializer.extend(new_initializers)

# # Filtrar fuera el tensor 'classes' de los inicializadores
# new_initializers = []
# for tensor in model.graph.initializer:
#     if tensor.name == "classes":
#         arr = numpy_helper.to_array(tensor).astype(np.float32)
#         new_tensor = numpy_helper.from_array(arr, name="classes")
#         new_initializers.append(new_tensor)
#         print("Convertido tensor 'classes' a float32")
#     else:
#         new_initializers.append(tensor)

# # Reemplazar todos los inicializadores con la nueva lista
# model.graph.ClearField("initializer")
# model.graph.initializer.extend(new_initializers)

# # Recorre los inicializadores y convierte los necesarios
# new_initializers = []
# for tensor in model.graph.initializer:
#     if tensor.name in tensors_a_cambiar and tensor.data_type == 7:  # int64
#         np_array = numpy_helper.to_array(tensor).astype(np.int32)
#         new_tensor = numpy_helper.from_array(np_array, name=tensor.name)
#         new_initializers.append(new_tensor)
#     else:
#         new_initializers.append(tensor)

# # Reemplaza todos los inicializadores del modelo
# del model.graph.initializer[:]
# model.graph.initializer.extend(new_initializers)

# Guarda el nuevo modelo
output_path = "ML_models/bdt_model_bb_jets_fixed.onnx"
onnx.save(model, output_path)

print(f"Modelo corregido guardado en {output_path}")
