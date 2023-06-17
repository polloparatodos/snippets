    //******************** Begin - Hand Grinder Lighting ********************
    //set ambient lighting strength
    glUniform1f(ambStrLoc, 0.4f);

    //set ambient color
    glUniform3f(ambColLoc, 0.3f, 0.3f, 0.3);

    // Diffuse light (fill light)
    glUniform3f(light1ColLoc, 0.6f, 0.6f, 0.6f);
    glUniform3f(light1PosLoc, -7.0f, 8.0f, 2.0f);
    glUniform1f(specInt1Loc, 0.4f);
    glUniform1f(highlghtSz1Loc, 0.6f);

    // Spotlight
    glUniform3f(light2ColLoc, 0.6f, 0.6f, 0.6f);
    glUniform3f(light2PosLoc, -6.0f, 8.0f, 0.0f);
    glUniform1f(specInt1Loc, 0.2f);
    glUniform1f(highlghtSz2Loc, 64.0f);

    ubHasTextureVal = true;
    glUniform1i(uHasTextureLoc, ubHasTextureVal);
    //******************** End - Hand Grinder Lighting ********************

    //******************** 1. Cylinder base - glass ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gCylinderMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(1.0f, 2.0f, 1.0f));
    // 2. do not rotate the object
    //rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-6.0f, 0.0f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureGlassId);

    // draws the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);		//bottom
    glDrawArrays(GL_TRIANGLE_FAN, 36, 36);		//top
    glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);	//sides

    glBindTexture(GL_TEXTURE_2D, 0);

    //******************** 2. cylinder body - green ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gCylinderMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(1.0f, 4.0f, 1.0f));
    // 2. do not rotate the object
    //rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-6.0f, 2.0f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureGreenPlasticId);

    // draws the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);		//bottom
    glDrawArrays(GL_TRIANGLE_FAN, 36, 36);		//top
    glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);	//sides

    glBindTexture(GL_TEXTURE_2D, 0);

    //******************** 3. handle top - metal ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gCylinderMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(0.23f, 0.5f, 0.23f));
    // 2. do not rotate the object
    //rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-6.0f, 6.0f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureMetalId);

    // draws the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);		//bottom
    glDrawArrays(GL_TRIANGLE_FAN, 36, 36);		//top
    glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);	//sides

    ////******************** 4. handle bar initial - metal ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gCylinderMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(0.125f, 1.0f, 0.125f));
    // 2. rotate the object
    rotation = glm::rotate(1.57f, glm::vec3(0.0f, 0.0f, 1.0f));
    // 3. position the object - mid point of previous object
    translation = glm::translate(glm::vec3(-5.0f, 6.25f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // draws the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);		//bottom
    glDrawArrays(GL_TRIANGLE_FAN, 36, 36);		//top
    glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);	//sides

    //******************** 5. handle bar downward mid - metal ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gCylinderMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(0.125f, 2.0f, 0.125f));
    // 2. rotate the object
    rotation = glm::rotate(-2.0f, glm::vec3(0.0f, 0.0f, 1.0));
    // 3. position the object
    translation = glm::translate(glm::vec3(-5.00f, 6.25f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // draws the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);		//bottom
    glDrawArrays(GL_TRIANGLE_FAN, 36, 36);		//top
    glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);	//sides

    //******************** 6. handle bar lower - metal ********************sw
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gCylinderMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(0.125f, 1.25, 0.125f));
    // 2. rotate the object
    rotation = glm::rotate(1.57f, glm::vec3(0.0f, 0.0f, 1.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-2.0f, 5.43f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // draws the triangles
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);		//bottom
    glDrawArrays(GL_TRIANGLE_FAN, 36, 36);		//top
    glDrawArrays(GL_TRIANGLE_STRIP, 72, 146);	//sides

    //******************** 7. handle bar -> knob - metal ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gTorusMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(1.25f, 1.25f, 1.25f));
    // 2. rotate the object
    rotation = glm::rotate(-1.1f, glm::vec3(0.0f, 0.0f, 1.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-2.62f, 6.53f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // draws the triangles - quarter torus
    glDrawArrays(GL_TRIANGLES, 0, (meshes.gTorusMesh.nVertices / 4));

    // ******************** 8. knob - wood ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gSphereMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(1.0f, 0.5f, 1.0f));
    // 2. rotate the object
    rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-1.64f, 7.3f, 1.0f));

    // model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    //******************** 9. knob top - wood ********************
    // activate the vbos contained within the mesh's vao
    glBindVertexArray(meshes.gSphereMesh.vao);

    // 1. scales the object
    scale = glm::scale(glm::vec3(1.0f, 0.5f, 1.0f));
    // 2. rotate the object
    rotation = glm::rotate(3.14f, glm::vec3(0.0, 1.0f, 0.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-1.44f, 7.3f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureKnobId);

    glDrawElements(GL_TRIANGLES, 600, GL_UNSIGNED_INT, (void*)0);

    //******************** 10. knob top - wood ********************
    // 1. scales the object
    scale = glm::scale(glm::vec3(1.0f, 1.5f, 1.0f));
    // 2. rotate the object
    rotation = glm::rotate(3.14f, glm::vec3(1.0, 0.0f, 0.0f));
    // 3. position the object
    translation = glm::translate(glm::vec3(-1.44f, 7.7f, 0.0f));
    // model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // draws the triangles
    glDrawElements(GL_TRIANGLES, 626, GL_UNSIGNED_INT, (void*)0);

    glBindTexture(GL_TEXTURE_2D, 0);
